# FingerBoard
## 这是fork @david-pzh的FingerBoard项目
### 给机械键盘添加指纹识别功能，这是Arduino固件的代码，详细项目介绍请看这篇文章:

[FingerBoard项目详情](https://github.com/david-pzh/FingerBoard)



### 使用方法：

在串口助手中打开Arduino串口号，波特率115200，放上手指会输出信息。

添加手指的方法：串口发送 **A,3 换行** 则表示注册手指为3号，根据串口提示放上手指收到ok即可。

删除手指的方法：直接添加一个覆盖，或者发送 **D 换行** 删除所有手指数据。

