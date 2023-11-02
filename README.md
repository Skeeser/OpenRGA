<div align="center">

<!-- <img alt="LOGO" src="assets/closure.jpg" width="256" height="256" /> -->

# OpenRGA

<br>

<div>
    <img alt="cpp" src="https://img.shields.io/badge/cpp-11-%2300599C">
    <img alt="platform" src="https://img.shields.io/badge/platform-Linux%20-blueviolet">
</div>
<div>
    <img alt="license" src="https://img.shields.io/github/license/Skeeser/OpenRGA">
    <img alt="commit" src="https://img.shields.io/github/commit-activity/m/Skeeser/OpenRGA?color=%23ff69b4">
    <img alt="stars" src="https://img.shields.io/github/stars/Skeeser/OpenRGA?style=social">
</div>
<br>

[简体中文](README.md)  | [English](README_EN.md) 

Library for common functions encapsulating Rockchip RGA

<br>

</div>

<br>

## 功能特性

- 函数的名称和OpenCV相似
- 在官方封装库基础上进一步封装

<br>

## 适用芯片平台

Rockchip RK3128 | RK3126c | RK3288 | RK3288w | RV1108 | RK3368 | RK3326 | RK3228 | RK3228H | RK3326 | RK1808 | RV1126 | RV1109 | RK3399 | RK3399pro | RK3566 | RK3568 | RK3588 | RK3326S | RV1106 | RV1103 | RK3528 | RK3562  

<br>

## 文件结构
- assets => 资源文件
- doc => 存放开发相关文档
- include => 头文件
- src => 源代码
- assets => 资源文件
- build => 编译文件

<br>

## 系统架构
Linux aarch64

<br>

## 快速开始

### 依赖检查
- cmake
- gtest (测试)
- [librga](https://github.com/airockchip/librga)

<br>

### 构建
#### 下载本项目
```shell
cd ~
git clone https://github.com/Skeeser/OpenRGA.git
```

#### 一行构建
```shell
cd ~/OpenRGA && sudo chmod +x ./build.sh && ./build.sh
```

<br>

### 编译
```shell
cd ~/OpenRGA/
mkdir build
cd build
cmake .. 
make
```

### 安装

```shell
sudo make install
```

<br>

## 使用指南
- 可以参考test文件夹中的测试文件和CMakeList.txt, 查看使用示例  
- 相关使用的函数API在(函数API)[doc/function_api.md]

<br>

## 如何贡献
如果你碰巧看见这个项目, 想要参与开发

可以查看这个文档 [如何参与开源项目](doc/github参与开源项目流程.md)

<br>

## 关于作者
keeser

<br>

## 现在功能已经支持
- [ ] RGA::resize 图像放缩

<br>

## 谁在用
[QuadcopterYolo](https://github.com/Skeeser/QuadcopterYolo)

<br>

## 参考项目
[rockchip-linux/rknpu (github.com)](https://github.com/rockchip-linux/rknpu)

[airockchip/librga (github.com)](https://github.com/airockchip/librga)

<br>

## 许可证
MPL 2.0