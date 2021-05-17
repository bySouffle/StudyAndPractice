//
// Created by by Souffle on 2021/5/16.
//

#ifndef STUDYANDPRACTICE_LOGSYSTEM_H
#define STUDYANDPRACTICE_LOGSYSTEM_H


#define _print_
#ifdef _print_
#define _print(format,...) printf("FILE: " __FILE__ ", LINE: %d : " format "\n", __LINE__ ,  ##__VA_ARGS__)
#else
#define _print(format,...)
#endif

#include "unistd.h"
#include "stdlib.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "sys/time.h"
#include "sys/stat.h"
#include "dirent.h"


#include "fcntl.h"
#include "string.h"
#include "string"
#include "vector"

#include <algorithm>


enum DeviceNo{
    kUART   = 0x00,
    kCAN    = 0x01,

    kUart0_ = 0x10,
    kUart1_ = 0x11,
    kUart2_ = 0x12,
    kUart3_ = 0x13,

    kCAN0_ = 0x20,
    kCAN1_ = 0x21,
    kCAN2_ = 0x22,
    kCAN3_ = 0x23,

};

enum ReturnStatus{
    kInvalid = -1,
    kOk = 0,
    kMapObjNumberError = -2,
    kOpenFileError = -3,
    kGetIndexError = -4,
};

#pragma pack(1)

typedef struct MapDeviceID{

    int device_id;
    bool operator == (const MapDeviceID &e){
        return (this->device_id);
    }
    std::string *buf;
    std::string *filedir;
    std::string filename;
    int fd;
}MapDeviceID_t;
#pragma pack()

enum LimitSize{
    kBufSize_ = 256, //1024,
    kFileSize_ = 1024, // 1024*1024,
    kUrlSize_ = 1024,
};

class RockLogSystem {
public:
    explicit RockLogSystem();
    ~RockLogSystem();

    static RockLogSystem* get_instance(){
        static RockLogSystem logSystem;
        return &logSystem;
    }


public:
//    //  补充日志信息逻辑控制
//    int add_log_info(DeviceNo id, const char* data);
    //  补充日志信息
    int add_log_info_item(int id, std::string *buf, const char *data);
    int add_log_info_item(int id, const char *data);

    //  初始化日志系统
    int init_log_system();
    //  设备id转换为log文件标识  0:uart 1:can
    int trans_id(int id, int type);
    //
private:
    std::vector<int> id_list_;
    std::vector<std::string > dirname_list_;
    std::vector<struct MapDeviceID> map_;
    std::vector<std::string > buf_list_;
    //  string buf
#if 0
    std::string uart0;
    std::string uart1;
    std::string uart2;
    std::string uart3;

    std::string can0;
    std::string can1;
    std::string can2;
    std::string can3;
#endif
    //  绝对路径
    std::string kAbsUrl_;
    std::string kscript_url_;
    //  初始化id vec
    int init_id_vec(std::vector<int>* id_list);
    int init_dirname_vec(std::vector<std::string >* dirname_list);
    //  初始化缓存区
    int init_buf_vec(std::vector<std::string >* buf_list);


    //  获取当前路径
    std::string get_current_url() ;
    //  获取初始化后的绝对路径
    std::string *get_abs_url();
    //  获取储存日志的文件夹路径
    std::vector<std::string >* get_device_vec();
    //  补充文件名到向量
    void add_device_name_vector(std::string device_name);
    //  创建日志文件夹及处理文件脚本
    void mk_device_logdir(std::vector<std::string> *dirname);
    //  获得日志文件夹路径
    std::string get_log_file_url(MapDeviceID_t* st);

    //  将日志插入buff
    void add_to_buff(std::string *buf, const char *data);
    //  获取当前时间
    std::string get_current_time();
    //  添加一个新的文件
    int get_new_log_file_fd(std::string *filename);
    //  获取一个新的文件名
    std::string get_new_filename();
    //  初始化文件名和fd
    int init_st_filename_fd(std::vector<struct MapDeviceID>* map);
    //  获取新文件写入的路径
    std::string get_new_filename_url(MapDeviceID_t *map_st);
    //  将buff内容写入到文件
    int write_buff2file(int fd, std::string *buff);
    //  获取当前啊文件描述符
    int get_current_fd();
    //  创建一个id与设备缓存区的映射
    int map_device_buf(std::vector<std::string >* buf, std::vector<struct MapDeviceID>* map);
//    std::vector<std::string*>* device_number;
    int map_device_id( std::vector<int >* device_list, std::vector<std::string >* device_name,
                       std::vector<struct MapDeviceID>* map);
    //  从id获取映射结构体index
    int get_mapItemIndex_from_id(int id, std::vector<struct MapDeviceID>* map);
    //  通过index返回map item结构体
    MapDeviceID_t *get_mapItem_from_index(int index, std::vector<struct MapDeviceID>* map);
    //  控制文件数量
    int limit_number_file(std::string url);
    //  获取脚本路径
    std::string get_runsh_url(MapDeviceID_t *item, std::string *sh_name);


};


#endif //STUDYANDPRACTICE_LOGSYSTEM_H
