# randomWalk
使用说明:   
stu.c, stu1.c, stu2.c均为打分对象, 修改名字为stu.c运行driver.sh即可计算出该程序的得分。   
   
打分逻辑:   
1.修改stu.c，在srand之前添加种子seed，在srand之后添加seed的输出，修改srand语句。   
2.stu.o的输出包括seed和字符数组m1，checker.c中二者都要记录。   
3.以seed为种子，模拟一个随机数序列。(这个序列和stu.o产生的结果是完全一样的！)   
4.随机数0-3对应4种方向，共有24种情况。根据每一种情况对应的方向和随机数序列，模拟产生字符数组m2，结果如果与读入的字符数组m1匹配，则该方向为stu.c中随机数
对应的方向。匹配思路如下:
1)根据随机数对应的方向，能产生移动但m1未移动则返回不匹配。   
2)根据随机数对于的方向，能产生移动且与m1匹配时，判断下一次产生的随机数对应的方向是否能移动。   
3)当移动到m1中最后一个A-Z出现的字符时，停止并返回匹配。   
4)匹配时，24种方向的唯一一种被记录。   
4.以seed为种子，根据记录的方向移动，模拟产生字符数组m3，返回出现的A-Z的个数。   
5.m1中字符的个数*SCORE/m3中字符的个数为分数返回。
   

当stu.o进入死循环时，终止当前stu.o的运行。   
不完善的地方：   
1.根据随机数对应的方向和随机数序列匹配m1时，当m1字符数极其少的时候，可能会有多个方向的组合匹配。   
2.修改stu.c部分逻辑不完善。

执行示例:
![image text](https://github.com/tbdyzm/randomWalk/blob/master/img/1.png)
