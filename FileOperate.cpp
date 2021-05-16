//
// Created by by Souffle on 2021/5/4.
//

#include "FileOperate.h"

void FileOperate::m_close_win_out() {
    bys_common::AddHead("窗口输出关闭");
//    printf("how are you?\n");
    close(1);
#if 0
    int status = system("pwd");
    if( status < 0 ){
        printf("===%s===\n", strerror(errno));
    }
#endif

    int fd = open("./test.txt", O_WRONLY);
    if( fd < 0 ){
        printf("===%s===\n", strerror(errno));
    }

//    dup2(fd,1);
    dup(1);
    printf(".........\n");


    printf("fine thanks, and you?\n");

    bys_common::AddEnd();

}

void FileOperate::m_fopen() {
    bys_common::AddHead("打开文件");

    FILE *m_file = nullptr;
    m_file = fopen("a.txt","w");
    if(m_file == nullptr)
    {
        printf("%s\n", strerror(errno));
    }

    fclose(m_file);
    m_file = nullptr;

    bys_common::AddEnd();

}

void FileOperate::m_fputc() {
    bys_common::AddHead("向文件写入一个字符");

    FILE *m_file = nullptr;
    m_file = fopen("a.txt", "w");
    if( m_file == nullptr )
    {
        printf("%s\n", strerror(errno));
    } else{
        fputc('a', m_file);
        fclose(m_file);
        m_file= nullptr;
    }

    bys_common::AddEnd();
}

void FileOperate::m_fgetc() {
    bys_common::AddHead("从文件读取一个字符");

    FILE *m_file = nullptr;
    m_file = fopen("b.txt","w");
    if ( m_file == nullptr )
    {
        printf("%s\n", strerror(errno));
    } else {
        std::string str("hello world");
        for(int i = 0; i < strlen(str.data()); ++i)
        {
            fputc(str.data()[i],m_file);
        }
    }
    fclose(m_file);
    m_file = nullptr;

    // read
    m_file = fopen("b.txt","r");
    if( m_file == nullptr )
    {
        printf("%s\n", strerror(errno));
    } else{
        char ch = 0;
        do{
            ch = fgetc(m_file);
            printf("%c ", ch);
        } while (ch != -1);
        fclose(m_file);
        m_file = nullptr;
        printf("\n");

    }

    bys_common::AddEnd();

}

void FileOperate::m_cat(std::string str) {
    FILE *m_file = fopen(str.data(),"r");
    if ( m_file == nullptr )
    {
        printf("%s\n", strerror(errno));
    } else {
        char ch = -1;
        while (true)
        {
            ch = fgetc(m_file);
            printf("%c", ch);
            if(feof(m_file))
            {
                fclose(m_file);
                break;
            }
        }
    }
}

void FileOperate::m_vi(std::string str) {
    FILE *m_file = nullptr;
    m_file = fopen(str.data(), "w");
    if ( m_file != nullptr )
    {
        char buf[1024] = {};
        while (true)
        {
            fgets(buf,sizeof(buf),stdin);
            printf("%s\n",buf);
            if (strncmp(buf,":wq",3) == 0)
            {
                fclose(m_file);
                break;
            }
            int i = 0;
            while (buf[i] != '\0')
            {
                fputc(buf[i],m_file);
                i++;
            }
        }
    }
}

void FileOperate::m_fputs() {
    std::string str("hello world");
    FILE *m_file = fopen("b.txt","w");
    if(m_file != nullptr)
    {
        fputs(str.data(), m_file);
    }
    fclose(m_file);
    m_file = nullptr;
}

void FileOperate::m_fgets() {
    char buf[1024];
    FILE *m_file = fopen("b.txt","r");
    if(m_file != nullptr)
    {
        fgets(buf,sizeof (buf), m_file);
    }
    printf("%s\n", buf);
    fclose(m_file);

    m_file = nullptr;
}

void FileOperate::m_rand_num_file() {
    unsigned int seed;
//    int result[500];
    int result;
    seed = time(0);
    srand(seed);

    char num_input[8];
    FILE * m_file = fopen("a.txt", "w");
    if(m_file != nullptr )
    {
        for(int i = 0; i<500 ; ++i)
        {
//        result[i] = rand();
            result = ( rand()% (100-1+1) + 1 );
            sprintf(num_input,"%d\n",result);
            fputs(num_input, m_file);
            memset(num_input,0,sizeof (num_input));

        }
        fclose(m_file);
        m_file = nullptr;
    }
}

void FileOperate::m_read_file_arr() {
    int a[1024] = {};
    char line_info[8] = {};
    FILE *m_file = fopen("a.txt", "r");
    if(m_file != nullptr)
    {
//        for(int i = 0;i<500;++i)
        int i = 0;
        while (true)
        {
            fgets(line_info,sizeof (line_info),m_file);
            printf("%s",line_info);
            a[i] = atoi(line_info);
            printf("-%d-\n",a[i]);
            if( feof(m_file) )
            {
                break;
            }
            i++;
        }
        fclose(m_file);
    }

}

void FileOperate::m_read_file_d_arr() {
    int a[1024] = {};
    char file_info[500][8]={};
    FILE *m_file = fopen("a.txt", "r");
    if(m_file != nullptr)
    {
        for(int i = 0;i<500;++i)
        {
            fgets(file_info[i],sizeof (file_info[i]),m_file);
//            printf("%s",file_info[i]);

        }
    }
//    printf("%s",file_info);

}

void FileOperate::m_fgets_read() {
    FILE *m_file = nullptr;
    char m_line[16][16] = {};
#if 01
    m_file = fopen("c.txt", "w");
    srand(time(0));

    char sym[5] = {'+', '-', '*', '/', '%'};
    for(int i = 0; i <= 15; ++i)
    {
        sprintf(m_line[i], "%d%c%d=\n", rand()%(10)+1,
                sym[rand()%(4)+1], rand()%(10)+1 );
        fputs(m_line[i], m_file);
//        memset(m_line, 0 ,sizeof (m_line));
    }
    fclose(m_file);

#endif
#if 1
    char read_line[20][16] = {};
    fopen("c.txt", "r");
    int i = 0;
    int num1,num2;
    char sym1;
    while (true)
    {
//        memset(m_line,0,8);
        fgets(read_line[i],16,m_file);
        if(strlen(read_line[i]) > 0)
        {
            printf("out %s\n", read_line[i]);
            sscanf(read_line[i],"%d%c%d=\n",&num1,&sym1,&num2);
            m_fgets_read_sub_exec(read_line[i],num1,num2,sym1);
            printf("out %s\n", read_line[i]);

        }

        if(feof(m_file))
        {
            break;
        }
        i++;
    }
    fclose(m_file);
    m_file = nullptr;

#endif

    m_file = fopen("c.txt","w");
    for(int i = 0; i< (sizeof (read_line)/sizeof (read_line[i]));++i)
    {
        fputs(read_line[i],m_file);
    }
    fclose(m_file);
    m_file = nullptr;
}


#if 1
void FileOperate::m_fgets_read_sub_exec(char *str_line, int num1, int num2, char sym) {

    int len = strlen(str_line);
    char result[6] = {};
    switch (sym) {
        case '+':
            sprintf(result,"%d\n",(num1+num2) );    break;
        case '-':
            sprintf(result,"%d\n",(num1-num2) );    break;
        case '*':
            sprintf(result,"%d\n",(num1*num2) );    break;
        case '/':
            sprintf(result,"%d\n",(num1/num2) );    break;
        case '%':
            sprintf(result,"%d\n",(num1%num2) );    break;
        default:break;
    }
    memcpy(&str_line[len-1],result,6);
}

void FileOperate::m_fwrite_fread() {
    FILE *m_file = nullptr;
    m_file = fopen("block.txt", "w");
    struct Block
    {
        int a;
        char b;
        short c;
    };
    Block block = {14,'a',12};

    int ret = fwrite(&block,1 ,sizeof (block),m_file);
    _print("ret = %d\n",ret);
    fclose(m_file);
    m_file = nullptr;
    memset(&block, 0 , sizeof (Block));
    // fread
    m_file = fopen("block.txt", "r");

    Block block_arr[4] = {};
    ret = fread(&block_arr,1, sizeof (block),m_file);

    for(int i = 0; i < 4; ++i)
    {
        _print("a[%d] b[%d] c[%d] ret[%d]", block_arr[i].a,block_arr[i].b,block_arr[i].c,ret);
    }
    fclose(m_file);
}


void FileOperate::m_fcopy(const char *srcfile, const char *dstfile) {

    printf ("cmp: %d \n", strcmp(srcfile,dstfile));
    if( strcmp(srcfile,dstfile)==0 )
    {
        printf("文件名相同!\n");
        return ;
    }

    FILE *fsrcfile = fopen(srcfile, "r");
    FILE *fdstfile = fopen(dstfile, "w");

    char buf[4*1024]={};
    int read_len = 0;

    while (true)
    {
        read_len = fread(buf,1,sizeof (buf),fsrcfile);
        printf("readline: %d\n", read_len);
        if(read_len == 0)
        {
            fclose(fsrcfile);
            break;
        }
        if (strlen(buf) != 0)
        {
            fwrite(buf, 1, strlen(buf), fdstfile);
        }

    }
    fclose(fdstfile);

}

void FileOperate::m_fopt_random() {
    FILE *m_file = fopen("rd.txt", "w");
    typedef struct Student
    {
        int a;
        int b;
        char c[12];
    }Student_t;

    Student st;
    Student_t s;
    st.a = 11;
    st.b = 11;
    strcpy(st.c,"hello_world");

    s.a = 22;
    s.b = 22;
    strcpy(s.c,"HELLOW_WORLD");

    int w_status, w_line;
    printf("current_line: %d\n", w_line);

    w_status = fwrite(&st,1,sizeof (Student),m_file);
    printf("w1_status: %d\n", w_status);
//    fseek(m_file,0,SEEK_SET);
    w_line = ftell(m_file);
    printf("current_line: %d\n", w_line);

    w_status = fwrite(&s,1,sizeof (Student),m_file);

    w_line = ftell(m_file);
    printf("current_line: %d\n", w_line);

    printf("w1_status: %d\n", w_status);

    fclose(m_file);

    m_file = fopen("rd.txt", "r");
    //  open 后的初始位置
    fseek(m_file,0,SEEK_CUR);
    long cur_line = ftell(m_file);
    printf("current_line: %d\n", cur_line);
    fseek(m_file,sizeof (Student),SEEK_CUR);

    cur_line = ftell(m_file);
    printf("current_line: %d\n", cur_line);

    Student_t r1 = {};
    fread(&r1,1,sizeof (Student_t),m_file);
    printf("[%d][%d][%s]\n", r1.a, r1.b, r1.c);
    rewind(m_file);
    fread(&r1,1,sizeof (Student_t),m_file);
    printf("[%d][%d][%s]\n", r1.a, r1.b, r1.c);
    fclose(m_file);
}

void FileOperate::m_pstruct_rw() {
    typedef struct Student{
        int id;
        int name_len;
        char *name;
    }Stu;

    Stu s;

    char *m_name = new char(16);
    s.name = m_name;
    memcpy(s.name, "shib",sizeof (16));
    s.id = 10;
    s.name_len = strlen(m_name);

    // write
    FILE *m_file = fopen("pstr_rw.txt","w");

    fwrite(&s.id,1,sizeof (s.id),m_file);
    fwrite(&s.name_len,1,sizeof (s.name_len),m_file);
    fwrite(s.name,1, strlen(s.name),m_file);
    printf("r id[%d] len(%d) name(%s)\n", s.id,s.name_len,m_name);

    fclose(m_file);
    m_file = nullptr;
    delete m_name;
    memset(&s,0,sizeof (s));

    // read
    m_file = fopen("pstr_rw.txt", "r");
    printf("stu [%d] s.name[%d]\n", sizeof (Stu),sizeof (s.name));
    fread(&s,1,sizeof (Stu)-sizeof (s.name),m_file);
    m_name = new char (s.name_len+1);
    fread(m_name,1,sizeof (m_name), m_file);
    printf("r id[%d] len(%d) name(%s)\n", s.id,s.name_len,m_name);

    fclose(m_file);
    m_file = nullptr;
    delete m_name;
    memset(&s,0,sizeof (s));

}

#endif
