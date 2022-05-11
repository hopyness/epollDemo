要 新写 序列化 clone t01 工程新开 工程

序列化 用protobuf

protobuf使用方法 
1 在https://github.com/protocolbuffers/protobuf/releases  选择下载同一个版本的 protobuf
我选择的是3.19.4
需要下载 protobuf-all-3.19.4.tar.gz 和
protoc-3.19.4-win32.zip protoc-3.19.4-win64.zip

protobuf-all-3.19.4.tar.gz 用于ubuntu 环境按照protobuf 运行环境
 protoc-3.19.4-win64.zip 是里面有个 exe  用在windows环境上 把 pro文件 转换成c++的文件

ubuntu按照  protobuf
把protobuf-all-3.19.4.tar.gz解压到一个文件夹下 直接执行
  先安装这几个工具
 sudo apt-get install autoconf
 sudo apt-get install libtool curl automake
 
  开始安装 protobuf
 ./autogen.sh
 ./configure
 make
 make check
 sudo make install
 sudo ldconfig
 
 安装完毕，查看版本
 protoc --version
 https://github.com/protocolbuffers/protobuf/releases
 https://github.com/google/protobuf.git
 
 https://www.cnblogs.com/timeddd/p/11081031.html
 
 windows 就是 简单的
 protoc.exe是编译器的名字；--proto_path指定对导入文件的搜索路径，若不指定，则为当前路径；
 --cpp_out指定生成c++文件的路径，--java_out和 --python_out分别是生成java和python代码的路径；
 path/file.proto是定义结构的.proto文件。 
 对C++ 而言
 protoc -I=./pbsrc --cpp_out=./pbinclude  ./pbsrc/122.proto

{ #include <google/protobuf/stubs/status.h>}     
{#include <google/protobuf/util/json_util.h>} 
添加这俩个可以调用
std::string temp;
 google::protobuf::util::MessageToJsonString(*msg, &temp);
 转json 打印
 
 已经简单实现 首发按照 protobuf 完成  下一步  完善收发包  

 