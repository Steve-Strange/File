# Pre

## 1.加数字

| clk          | I     |
| ------------ | ----- |
| **clr**      | I     |
| **in [1:0]** | **I** |
| **out**      | **O** |

电路外观

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220927224026983.png" alt="image-20220927224026983" style="zoom: 33%;" />

串行输入，in每次输入为2‘b00代表1，2'b10代表2，2'b11代表3

当输入总和**大于等于5时**输出为1，并且加和清零

搭建merely型有限状态机

## 2.识别序列101

识别序列101

| input      | clk       |
| ---------- | --------- |
| **input**  | **input** |
| **input**  | **in**    |
| **output** | **out**   |

可以重叠识别 例10101

reset为**异步复位**，当reset为高电平时，状态恢复到一开始状态

要求为merely型状态机

## 3.开根号

数据范围 1~2^16

不要遍历，会超时

tips:二分查找。。