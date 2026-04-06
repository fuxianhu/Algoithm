#include <bits/stdc++.h>

#define NUMBER_SIZE 0x20

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 0xA + ch - '0', ch = getchar();
    }
    return x * f;
}

inline void toBit(int RawData, bool *Bytes)
{
    int index = 0;
    int data = RawData;
    for (int i = 0; i < NUMBER_SIZE; i++)
    {
        Bytes[i] = 0;
    }
    if (RawData < 0)
    {
        data = -RawData;
    }
    while (data != 0x0)
    {
        Bytes[index] = (bool)(data % 0x2);
        data /= 0x2;
        index++;
    }
    if (RawData < 0)
    {
        for (int i = 0; i < NUMBER_SIZE; i++)
        {
            Bytes[i] = !Bytes[i];
        }
        int carry = 1;
        for (int i = 0; i < NUMBER_SIZE; i++)
        {
            int sum = Bytes[i] + carry;
            Bytes[i] = sum % 2;
            carry = sum / 2;
        }
    }
}

int a, b;
bool _a[NUMBER_SIZE], _b[NUMBER_SIZE], _addResult[NUMBER_SIZE];

inline void RippleCarryAdder(bool *x, bool *y, bool *result)
{
    register int c = 0;
    for (register int i = 0; i < NUMBER_SIZE; i++)
    {
        result[i] = x[i] ^ y[i] ^ c;
        c = (x[i] && y[i]) || ((x[i] ^ y[i]) && c);
    }
}

inline std::string toDecimalism(bool *resultData)
{
    std::string ans = "";
    int cnt = 0;
    bool negative = resultData[31];
    if (negative)
    {
        bool temp[NUMBER_SIZE];
        for (int i = 0; i < NUMBER_SIZE; i++)
        {
            temp[i] = !resultData[i];
        }
        int carry = 1;
        for (int i = 0; i < NUMBER_SIZE; i++)
        {
            int sum = temp[i] + carry;
            temp[i] = sum % 2;
            carry = sum / 2;
        }
        for (int i = 0; i < NUMBER_SIZE; i++)
        {
            cnt += temp[i] * (1 << i);
        }
        cnt = -cnt;
    }
    else
    {
        for (register int i = 0; i < NUMBER_SIZE; i++)
        {
            cnt += resultData[i] * (1 << i);
        }
    }
    if (cnt == 0)
    {
        return "0";
    }
    if (cnt < 0)
    {
        ans += '-';
        cnt = -cnt;
    }
    std::string digits = "";
    while (cnt != 0)
    {
        digits += (cnt % 0xA) + '0';
        cnt /= 0xA;
    }
    for (register int i = 0; i < digits.length() / 2; i++)
    {
        char temp = digits[i];
        digits[i] = digits[digits.length() - i - 1];
        digits[digits.length() - i - 1] = temp;
    }
    ans += digits;
    return ans;
}

int main()
{
    a = read();
    b = read();
    toBit(a, _a);
    toBit(b, _b);
    RippleCarryAdder(_a, _b, _addResult);
    std::string AAddBStringResult = toDecimalism(_addResult);
    for (int i = 0; i < AAddBStringResult.length(); i++)
    {
        putchar(AAddBStringResult[i]);
    }
    putchar('\n');
    std::cout.flush();
    return 0;
}
