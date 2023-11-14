## todos
- [ ] 让imread摆脱opencv依赖


## gtest
### 安装
```shell
cd ~
git clone https://github.com/google/googletest.git
sudo apt-get install cmake
cd ~/googletest/
mkdir build
cd build/
cmake ..
make
sudo make install
```
 
<br>







## 参考网站

[RK3588 RGA 图像操作-CSDN博客](https://blog.csdn.net/weixin_46935110/article/details/129844176)

[rknpu/rknn/rknn_api/examples/rknn_yolov5_demo/src at master · rockchip-linux/rknpu (github.com)](https://github.com/rockchip-linux/rknpu/tree/master/rknn/rknn_api/examples/rknn_yolov5_demo/src)

[rockchip-linux/rknpu (github.com)](https://github.com/rockchip-linux/rknpu)

[airockchip/librga (github.com)](https://github.com/airockchip/librga)

- V4L2 + RGA
  - 用V4L2获取视频码流，然后用RGA将其由YUV422格式转换为BGR格式

- 新建一个仓库，专门封装

<[【RK3588-linux开发】3、训练yolov5并在RK3588上运行_linux rga 下载-CSDN博客](https://blog.csdn.net/qq_32768679/article/details/124674803)>

