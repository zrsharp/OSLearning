# 操作系统第三次实验

本程序借助脚本直接按顺序输出实验所有步骤的结果，一步到位。

## 安装

右上角有个克隆按钮，在里面选择下载 .zip 文件，然后解压。

或者安装 git 后直接 git clone： 
```bash
sudo apt install git

git clone https://github.com/zrsharp/OSExperiment3.git
```
## 启动
目录下有个 experiment3.sh 脚本，然后直接运行即可,命令如下：

```bash
./experiment3.sh
```
**由于脚本中要复制动态链接库到 /usr/lib/ ，需要 sudo 提权，所以中途可能会提示输入密码**。

tips：如果sh脚本无法执行，则需给其添加权限，命令如下：

```bash
sudo chmod +x experiment3.sh
```
输入密码回车之后，再运行 ```./experiment3.sh``` 就不会出错了。

## 程序输出说明

结果直接显示在终端上，而最后一问动态加载三个阶段（加载前，加载后，关闭后）的内存情况，分别会保存在当前目录的如下三个文件中：
- before_loading.txt
- after_load.txt
- after_release.txt




