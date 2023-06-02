#include <bits/stdc++.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string>
using namespace std;

class KeyValue {
   public:
    string key;
    string value;
};

/**
 * @brief 自己写的字符串按照单词分割函数，因为mapReduce中经常用到
 *
 * @param text 传入的文本内容，数据量极大
 * @param length 传入的字符串长度
 * @return vector<string> 返回各个分割后的单词列表
 */
vector<string> split(char* text, int length) {
    vector<string> str;
    string tmp = "";
    for (int i = 0; i < length; i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') ||
            (text[i] >= 'a' && text[i] <= 'z')) {
            tmp += text[i];
        } else {
            if (tmp.size() != 0)
                str.push_back(tmp);  // 获取到一个单词
            tmp = "";
        }
    }
    if (tmp.size() != 0)
        str.push_back(tmp);
    return str;  // 返回单词列表
}

/**
 * @brief mapFunc，需要打包成动态库，并在worker中通过dlopen以及dlsym运行时加载
 * @param kv 将文本按单词划分并以出现次数代表value长度存入keyValue
 * @return 类似{"my 11111", "you 111"} 即文章中my出现了5次，you出现了3次
 */
extern "C" vector<KeyValue> mapF(
    KeyValue
        kv) {  // 输入kv，得到kv，这就是论文的思路。输入的是kv的value为文本，输出的kv的value为单词出现次数，输出的kv的key为单词
    vector<KeyValue> kvs;
    int len = kv.value.size();
    char content[len + 1];  // 为什么要加1，答：因为字符串最后有一个'\0'
    strcpy(content, kv.value.c_str());
    vector<string> str = split(content, len);
    for (const auto& s : str) {
        KeyValue tmp;
        tmp.key = s;
        tmp.value = "1";  // value为什么使用string表示，答：因为mapReduce中的value可以是任意类型吗？还是说只是在按照论文的思路实现
        kvs.emplace_back(tmp);
    }
    return kvs;
}

/**
 * @brief redecuFunc，也是动态加载，输出对特定keyValue的reduce结果
 * @param reduceTaskIdx 好像多余了，后来才发现的，放着也没事，懒得重新编译.so了
 * @return vector<string>
 */
extern "C" vector<string> reduceF(vector<KeyValue> kvs, int reduceTaskIdx) {
    vector<string> str;
    string tmp;
    for (const auto& kv : kvs) {
        str.push_back(to_string(kv.value.size()));
    }
    return str;  // 输出每个单词出现的次数
}
