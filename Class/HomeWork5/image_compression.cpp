#include <iostream>
#include <vector>
using namespace std;

// 计算整数的二进制位数
int length(int i)
{
    int k = 1;
    i /= 2;
    while (i > 0)
    {
        k++;
        i /= 2;
    }
    return k;
}

// 图像压缩函数
void Compress(int n, int p[], int s[], int l[], int b[])
{
    int Lmax = 256, header = 11;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = length(p[i]);
        int bmax = b[i];
        s[i] = s[i - 1] + bmax;
        l[i] = 1;
        for (int j = 2; j <= i && j <= Lmax; j++)
        {
            if (bmax < b[i - j + 1])
                bmax = b[i - j + 1];
            if (s[i] > s[i - j] + j * bmax)
            {
                s[i] = s[i - j] + j * bmax;
                l[i] = j;
            }
        }
        s[i] += header;
    }
}

// 回溯函数，确定最优分段
void Traceback(int n, int &i, int s[], int l[])
{
    if (n == 0)
        return;
    Traceback(n - l[n], i, s, l);
    s[i++] = n - l[n];
}

// 输出压缩结果
void Output(int s[], int l[], int b[], int n)
{
    cout << "图像压缩后的最小空间为: " << s[n] << endl;
    int m = 0;
    Traceback(n, m, s, l);
    s[m] = n;
    cout << "将原灰度序列分成" << m << "段序列段" << endl;
    for (int j = 1; j <= m; j++)
    {
        l[j] = l[s[j]];
        b[j] = b[s[j]];
    }
    for (int j = 1; j <= m; j++)
    {
        cout << "段" << j << ": 长度=" << l[j] << ", 存储位数=" << b[j] << endl;
    }
}

int main()
{
    // 示例灰度值序列 (4x4 图像)
    int p[] = {0, 10, 9, 12, 40, 50, 35, 15, 12, 8, 10, 9, 15, 11, 130, 160, 240};
    int n = 16; // 图像像素数

    // 初始化数组
    int *s = new int[n + 1];
    int *l = new int[n + 1];
    int *b = new int[n + 1];

    // 执行压缩
    Compress(n, p, s, l, b);
    // 输出b,s,l数组
    cout << "b数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "s数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << "l数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;

    // 输出结果
    Output(s, l, b, n);
    // 输出b,s,l数组
    cout << "b数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "s数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << "l数组:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
    // 释放内存
    delete[] s;
    delete[] l;
    delete[] b;

    return 0;
}