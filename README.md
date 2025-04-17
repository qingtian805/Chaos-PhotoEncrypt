# Chaos-Encryption-CPP

这个项目使用Logistic混沌映射加密图像。  
原谅我没有在代码中增加注释，写毕设的时间太短了，但这应该只是暂时的。  

## 第三方库依赖(Required Librarys)

图像处理使用OpenCV 4.7.0（without opencv-contrib）。

## 算法介绍(Introduction)

算法首先使用普适Arnold变换对图像进行三次置乱迭代，之后对迭代结果进行序列密码加密。序列密码的随机数生成器数学原理为Logistic混沌映射。  

## 设计目的(Aim)

设计目的是实现一个较为快速的基于Logistic混沌映射的随机数生成器。  
设计了一个定点数类型chaos-fpoint，使用超长整形作为运算基础，试图通过整数运算代替浮点来加速随机数的生成。  

然而测试结果是还不如双精度来得快，也就精度上去了一点点。chaos-rng-sped-test测试程序的结果是生成一千三百万参数需要300-500ms。算法整体的话，一千一百万（picc.jpg）像素的图片，大概需要5s左右来加解密。  

## 目前缺陷(Known Issue)

* 因为chaos-fpoint类的乘法实现，在Logistic映射中不能使Lambda参数等于4（虽然这个参数对于映射本身是有效的）  
* 三次普适Arnold变换对于横坐标长度小于纵坐标长度的图像（见测试图像的picb.jpg），如720*1280的这种，并不能很好的置乱。  

## 正在进行(Working in Progress)

正在更新Arnold模块，新模块用计算矩阵参数代替直接变换图像的迭代。