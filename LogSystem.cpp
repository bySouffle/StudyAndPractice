//
// Created by by Souffle on 2021/5/16.
//

#include "LogSystem.h"

RockLogSystem::RockLogSystem() {
    init_log_system();
}

std::string RockLogSystem::get_current_url() {
    char url[kUrlSize_] = {};
    if (!getcwd(url, kUrlSize_)) {
        perror("获取当前目录失败！\n");
    } else {
        std::string str_url;
        str_url.append(url);
        return str_url;
    }
#if 0
    char abs_path[1024] = {};
    int cnt = readlink("/proc/self/exe", abs_path, 1024);//获取可执行程序的绝对路径
    if (cnt < 0 || cnt >= 1024) {
        return NULL;
    }

    //最后一个'/' 后面是可执行程序名，去掉devel/lib/m100/exe，只保留前面部分路径
    for (int i = cnt; i >= 0; --i) {
        if (abs_path[i] == '/') {
            abs_path[i + 1] = '\0';
            break;
        }
    }

    std::string url(abs_path);
    printf("log system abs url : %s\n", url.data());
    return url;
#endif
}

void RockLogSystem::mk_device_logdir(std::vector<std::string> *dirname) {
    std::string url = get_current_url();


    for (int i = 0; i < dirname->size(); ++i) {
        std::string device_dir = url + dirname->at(i);  //uart_log_dir can_log_dir
        if (opendir(device_dir.data()) == nullptr) {
            mkdir(device_dir.data(), 0775);
        }
        std::string limit_file_sh = "#! /bin/bash\n"
                                    "# 定义监测文件夹\n"
                                    "BACK_DIR=$(dirname $(readlink -f $0))\n"
                                    "count2=$(ls $BACK_DIR -l | grep \"/*.log\" | wc -l)\n"
                                    "if [ $count2 -gt 3 ]; then\n"
                                    "   rm $(ls -rt | head -n1)\n"
                                    "fi\n";

        std::string clear_uart_json_filename = device_dir + "/limit_number_logfile.sh";
        int fd = open(clear_uart_json_filename.data(),
                      O_RDWR | O_CREAT | O_TRUNC, 0775);
        write(fd, limit_file_sh.data(), limit_file_sh.size());
        close(fd);


    }
#if 0
    else if (strcmp(dirname->at(i).data(), "/can_log_dir") == 0) {

            std::string can_clear_sh = "#! /bin/bash\n"
                                       "# 定义监测文件夹\n"
                                       "BACK_DIR=$(dirname $(readlink -f $0))\n"
                                       "UART_DIR=${BACK_DIR}/can_log_dir\n"
                                       "cd $UART_DIR\n"
                                       "count2=$(ls $UART_DIR -l | grep \"/*.log\" | wc -l)\n"
                                       "if [ $count2 -gt 3 ]; then\n"
                                       "   rm $(ls -rt | head -n1)\n"
                                       "fi\n";
            std::string clear_can_json_filename = device_dir + "/limit_number_logfile.sh";
            int fd = open(clear_can_json_filename.data(),
                          O_RDWR | O_CREAT | O_TRUNC, 0775);
            write(fd, can_clear_sh.data(), can_clear_sh.size());
            close(fd);
        } else {
            std::string default_clear_sh = "#! /bin/bash\n"
                                           "# 定义监测文件夹\n"
                                           "BACK_DIR=$(dirname $(readlink -f $0))\n"
                                           "UART_DIR=${BACK_DIR}/default_log_dir\n"
                                           "cd $UART_DIR\n"
                                           "count2=$(ls $UART_DIR -l | grep \"/*.log\" | wc -l)\n"
                                           "if [ $count2 -gt 3 ]; then\n"
                                           "   rm $(ls -rt | head -n1)\n"
                                           "fi\n";
            std::string clear_default_json_filename = device_dir + "/clear_default_log.sh";
            int fd = open(clear_default_json_filename.data(),
                          O_RDWR | O_CREAT | O_TRUNC, 0775);
            write(fd, default_clear_sh.data(), default_clear_sh.size());
            close(fd);
        }
#endif


}


void RockLogSystem::add_device_name_vector(std::string device_name) {
    std::vector<std::string> *dirname = get_device_vec();
    dirname->push_back(device_name);
}

std::vector<std::string> *RockLogSystem::get_device_vec() {
    return &dirname_list_;
}

void RockLogSystem::add_to_buff(std::string *buf, const char *data) {
    buf->append(data);
}

int RockLogSystem::add_log_info_item(int id, std::string *buf, const char *data) {
    int index = get_mapItemIndex_from_id(id, &map_);
    MapDeviceID_t *item = get_mapItem_from_index(index, &map_);

    if ((buf->length() + strlen(data)) > kBufSize_)    // 超过缓存区大小，将缓存区数据写入文件清空缓存区
    {
        write_buff2file(item->fd, item->buf);
        item->buf->clear();
    }
    //  检查文件大小是否超过范围
    struct stat file_stats = {};
    stat(item->filename.data(), &file_stats);
    if (file_stats.st_size > kFileSize_) {
        if (item->fd > 0) {
            sync();
            close(item->fd);
            item->filename.clear();
            item->fd = kInvalid;
            item->filename.append(get_new_filename());
            item->fd = get_new_log_file_fd(&item->filename);
            limit_number_file(item->filedir);
        }
    }
    add_to_buff(item->buf, data);


    return 0;
}

std::string RockLogSystem::get_current_time() {
    time_t ptime;
    struct tm *tmTime;
    struct timeval m_time = {};
    time(&ptime);
    tmTime = localtime(&ptime);
    gettimeofday(&m_time, nullptr);
    char datetime[32];

    sprintf(datetime, "%04d-%02d-%02d %02d:%02d:%02d",
            tmTime->tm_year + 1900, tmTime->tm_mon + 1,
            tmTime->tm_mday, tmTime->tm_hour,
            tmTime->tm_min, tmTime->tm_sec);

    std::string timestamp = {datetime};

    return timestamp;
}

int RockLogSystem::get_new_log_file_fd(std::string *filename) {
    int fd = open(filename->data(), O_RDWR | O_CREAT | O_TRUNC, 0775);
    return fd;
}

std::string RockLogSystem::get_new_filename() {
    std::string filename = get_current_time();
    filename.append(".log");
    return filename;
}

int RockLogSystem::write_buff2file(int fd, std::string *buff) {
    int status = write(fd, buff->data(), buff->size());
    _print("write_status: %d\n", status);
    return status;
}

int RockLogSystem::map_device_id(std::vector<int> *device_list, std::vector<std::string> *device_name,
                                 std::vector<struct MapDeviceID> *map) {
    int size_id = static_cast<int> ( device_list->size());
    int size_dev = static_cast<int> ( device_name->size());
    if (size_id != size_dev) {
        return kMapObjNumberError;
    }
    for (int i = 0; i < size_id; ++i) {
        MapDeviceID map_t = {};
        map_t.device_id = device_list->at(i);
        map_t.filedir = &device_name->at(i);
        map->push_back(map_t);
    }
    return kOk;
}

int RockLogSystem::get_mapItemIndex_from_id(int id, std::vector<struct MapDeviceID> *map) {
    MapDeviceID_t it_t = {};
    it_t.device_id = id;
    int index = kInvalid;
    for (int i = 0; i < map->size(); ++i) {
        if (map->at(i).device_id == id) {
            index = i;
            break;
        }
    }
    return index;

//    if (item != map->end()) {
//        int index;
//        index = std::distance((*map).begin(), item);
//        return index;
//    } else {
//
//        return kMapObjNumberError;
//
//    }

}

MapDeviceID_t *RockLogSystem::get_mapItem_from_index(int index, std::vector<struct MapDeviceID> *map) {

    return &map->at(index);
}


int RockLogSystem::limit_number_file(std::string *url) {
    url->insert(0, ".");
    url->append("/limit_number_logfile.sh");
    system(url->data());
    return 0;
}

int RockLogSystem::add_log_info_item(int id, const char *data) {
    int index = get_mapItemIndex_from_id(id, &map_);
    if (index == kInvalid) {
        return kGetIndexError;
    }
    MapDeviceID_t *item = get_mapItem_from_index(index, &map_);

    if ((item->buf->length() + strlen(data)) > kBufSize_)    // 超过缓存区大小，将缓存区数据写入文件清空缓存区
    {
        write_buff2file(item->fd, item->buf);
        item->buf->clear();
    }
    //  检查文件大小是否超过范围
    struct stat file_stats = {};
    std::string file_url = get_new_filename_url(item);
    stat(file_url.data(), &file_stats);
    if (file_stats.st_size > kFileSize_) {
        if (item->fd > 0) {

            close(item->fd);
            item->filename.clear();
            item->fd = kInvalid;
            item->filename.append(get_new_filename());
            std::string new_file_url = get_new_filename_url(item);
            item->fd = get_new_log_file_fd(&new_file_url);
            limit_number_file(item->filedir);
        }
    }
    add_to_buff(item->buf, data);


    return 0;
}

int RockLogSystem::init_log_system() {
    /* 1. 补充对应列表
     * 2. map
     * 3. 创建文件夹及limit脚本
     * 4. 补充初始化的fd和文件名
     * 5. map id 和 缓存区
     * */

    //  1.
#if 0
    for (int i = 0; i < 8; ++i) {
        if (i < 4) {
            id_list_.push_back(0x10 + i);
            dirname_list_.push_back(std::string("/UartLog_") + std::to_string(i));
        }

        if (i > 3) {
            id_list_.push_back(0x20 + i - 4);
            dirname_list_.push_back(std::string("/CANLog_") + std::to_string(i - 4));
        }
    }
#endif
    init_id_vec(&id_list_);
    init_dirname_vec(&dirname_list_);
    //  2.
    map_device_id(&id_list_, &dirname_list_, &map_);
    //  3.
    mk_device_logdir(&dirname_list_);
    //  4.
    init_st_filename_fd(&map_);
    //  5.
    init_buf_vec(&buf_list_);
    map_device_buf(&buf_list_, &map_);

}

std::string RockLogSystem::get_new_filename_url(MapDeviceID_t *map_st) {
    std::string file_url = get_current_url();
    file_url.append(*map_st->filedir);
    file_url.append("/");
    file_url.append(map_st->filename);

    return file_url;
}

int RockLogSystem::init_st_filename_fd(std::vector<struct MapDeviceID> *map_) {

    for (int i = 0; i < map_->size(); ++i) {
        std::string filename = get_new_filename();
        if (!map_->at(i).filename.empty()) {
            map_->at(i).filename.clear();
        }
        map_->at(i).filename.append(filename.data());
        MapDeviceID_t *map = &map_->at(i);
        std::string url = get_new_filename_url(map);

        int fd = get_new_log_file_fd(&url);
        if (fd > 0) {
            map_->at(i).fd = fd;
        } else {
            return kOpenFileError;
        }
    }
    return kOk;
}

int RockLogSystem::init_id_vec(std::vector<int> *id_list) {
    id_list->clear();
    for (int i = 0; i < 8; ++i) {
        if (i < 4) {
            id_list->push_back(0x10 + i);
        }
        if (i > 3) {
            id_list->push_back(0x20 + i -4);
        }
    }
    return 0;
}

int RockLogSystem::init_dirname_vec(std::vector<std::string> *dirname_list) {
    dirname_list->clear();
    for (int i = 0; i < 8; ++i) {
        if (i < 4) {
            dirname_list->push_back(std::string("/UartLog_") + std::to_string(i));
        }
        if (i > 3) {
            dirname_list->push_back(std::string("/CANtLog_") + std::to_string(i - 4));
        }
    }
    return 0;
}

int RockLogSystem::init_buf_vec(std::vector<std::string> *buf_list) {
    if (!buf_list->empty()) {
        buf_list->clear();
    }
    for (int i = 0; i < 8; ++i) {
        buf_list->push_back("");
    }
    return 0;
}

int RockLogSystem::map_device_buf(std::vector<std::string> *buf, std::vector<struct MapDeviceID> *map) {
    int num_st = static_cast<int> ( map->size());
    int num_buf = static_cast<int> ( buf->size());
    if (num_st != num_buf) {
        return kMapObjNumberError;
    }
    for (int i = 0; i < num_st; ++i) {
        map->at(i).buf = &buf->at(i);
    }
    return kOk;
    return 0;
}

int RockLogSystem::trans_id(int id, int type) {
    int tran_id = kInvalid;
    if (type == 0) // uart
    {
        tran_id = 0x10 + id;
    } else if(type == 1){
        tran_id = 0x20 +id;
    }
    return tran_id;
}

RockLogSystem::~RockLogSystem() {
    for(int i = 0 ; i<map_.size(); ++i){
        write_buff2file(map_.at(i).fd, map_.at(i).buf);
        close(map_.at(i).fd);

    }
}




