## Linux系统与调试工具

### 1. 查看进程使用的端口？

netstat -tunlp | grep <pid> 或 lsof -i -P -n | grep <pid>

### 2. gdb常用命令？

break 设置断点；

run 运行程序；

next 单步执行；

print var 打印变量；

bt 查看堆栈回溯。

### 3. strace 与 ltrace 区别？

strace 跟踪系统调用；

ltrace 跟踪库函数调用；

都可用于调试运行时问题。

### 4. 检查内存泄漏的工具？

valgrind --leak-check=full ./program

### 5. 配置网络接口命令？

ifconfig eth0 192.168.1.10 netmask 255.255.255.0 up
# 或使用 ip 工具：
ip addr add 192.168.1.10/24 dev eth0

### 6. 查看CPU/内存/IO使用率的命令？

top：总体资源占用；

htop：可视化；

iotop：IO使用；

free -h：内存使用。

### 7. Linux 中的软中断和硬中断？

硬中断：由硬件触发（如网卡接收）；

软中断：内核中断处理后延迟执行的任务（如网络协议栈）。

### 8. 如何查看某个进程的线程？

ps -T -p <pid>

### 高频面试问题拓展：

什么是 page fault？怎么定位？

描述一次你用 perf 分析系统瓶颈的过程。

如何用 ftrace/bpftrace 追踪函数调用？

怎么用 pahole 查看结构体布局和空洞？

如何使用 IO 路径 tracing 定位磁盘瓶颈？

TCP 抓包分析的基本流程（tcpdump + wireshark）？
