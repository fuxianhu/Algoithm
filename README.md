# Algoithm

我们首先写一个 $3$ KB 的 [A + B Problem](https://www.luogu.com.cn/problem/P1001)，作为 `RawA+B.cpp`，原理如下：

- 快读 A 和 B
- 转为二进制
- 通过串行进位加法器（Ripple Carry Adder, RCA）做加法运算
- 转十进制
- 转字符串并逐字输出

可是代码才 $143$ 行，于是...

```bash
g++ -E -C .\RawA+B.cpp -o .\15wLinesA+B.cpp
```

## $5.14$ MB ！可惜洛谷做多只能交 $512$ KB. qwq
