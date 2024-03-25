#include <iostream>

int StringLength(const char* str);
char* StringCopy(char*& dest, const char* src);
char* StringConcat(char*& dest, const char* src);

int CharCompare(char ch1, char ch2);
int StringCompare(const char* str1, const char* str2);

char* StringSubstring(const char* str, int index, int length);

int StringFind(const char* str, const char* findStr, int index = 0);
char* StringReplace(const char* str, const char* oldStr, const char* newStr, int index = 0);


int main()
{
    //std::cout << StringLength("Hello");
    
    /*char* str = nullptr;
    StringCopy(str, "Hello");
    std::cout << str << "\n";

    char* str2 = nullptr;
    StringCopy(str2, " world");
    std::cout << str2 << "\n";

    StringConcat(str, str2);
    std::cout << str << "\n";*/


    //std::cout << StringSubstring("Hello world", 0, StringLength("Hello world") - 0) << "\n";

    //std::cout << StringFind("Hello wwow", "wow") << "\n";

    char* s = StringReplace("Hello world, Hello people", "Hello", "By");
    std::cout << s << "\n";
    
}

int StringLength(const char* str)
{
    int length{};
    while (str[length])
        length++;
    return length;
}

char* StringCopy(char*& dest, const char* src)
{
    if (dest) delete[] dest;
    
    int length = StringLength(src);
         
    dest = new char[length + 1];
    for (int i{}; i < length; i++)
        dest[i] = src[i];
    dest[length] = '\0';

    return dest;
}

char* StringConcat(char*& dest, const char* src)
{
    int length = StringLength(dest) + StringLength(src);

    char* tempString = new char[length + 1];

    int index{};

    for (int i{}; i < StringLength(dest); i++)
        tempString[index++] = dest[i];

    for (int i{}; i < StringLength(src); i++)
        tempString[index++] = src[i];

    tempString[length] = '\0';

    delete[] dest;
    dest = tempString;

    return dest;
}

int CharCompare(char ch1, char ch2)
{
    return ch1 - ch2;
}

int StringCompare(const char* str1, const char* str2)
{
    int length1 = StringLength(str1);
    int length2 = StringLength(str2);

    int length = (length1 < length2) ? length1 : length2;

    for (int i{}; i < length; i++)
    {
        int result = CharCompare(str1[i], str2[i]);
        if (result)
            return result;
    }

    return length1 - length2;
}

char* StringSubstring(const char* str, int index, int length)
{
    int lengthStr = StringLength(str);
    if (index > lengthStr || index + length > lengthStr || index < 0 || length < 0)
        return nullptr;

    char* strResult = new char[length + 1];

    for (int i{}; i < length; i++)
        strResult[i] = str[i + index];
    strResult[length] = '\0';

    return strResult;
}

int StringFind(const char* str, const char* findStr, int index)
{
    char first{ findStr[0] };
    
    int length{ StringLength(str) };
    int lengthFind{ StringLength(findStr) };

    int indexResult{ index };

    while (true)
    {
        while (str[indexResult] && str[indexResult] != first)
            indexResult++;
        
        if (!str[indexResult]) return -1;

        int i{};
        while (str[indexResult + i]
            && findStr[i]
            && (str[indexResult + i] == findStr[i]))
        {
            i++;
        }
        if (i == lengthFind) return indexResult;
        if (!str[indexResult + i]) return -1;

        indexResult += i;
    }

    
        

    


    return 0;
}

char* StringReplace(const char* str, const char* oldStr, const char* newStr, int index)
{
    char* dest = new char;
    *dest = '\0';

    int lengthStr{ StringLength(str) };
    int lengthOld{ StringLength(oldStr) };
    int begin{ index };
    int end{};

    while (end < lengthStr)
    {
        end = StringFind(str, oldStr, begin);
        if (end == -1)
            break;
        StringConcat(dest, StringSubstring(str, begin, end - begin));
        StringConcat(dest, newStr);
        begin = end + lengthOld;
    }

    StringConcat(dest, StringSubstring(str, begin, lengthStr - begin));

    return dest;
}
