#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 定义图书信息结构体
struct BookInfo {
    char category[20];   // 分类号
    char title[50];      // 书名
    char author[30];     // 编者
    char publisher[50];  // 出版社
    char publish_date[20];  // 出版年月
    float price;         // 价格
};

// 声明函数
void readInfoFromFile(struct BookInfo* books, int* count);
void saveInfoToFile(const struct BookInfo* books, int count);
void inputInfo(struct BookInfo* books, int* count);
void browseInfo(const struct BookInfo* books, int count);
void searchInfo(const struct BookInfo* books, int count);
void deleteInfo(struct BookInfo* books, int* count);
void modifyInfo(struct BookInfo* books, int count);

// 主函数
int main() {
    struct BookInfo books[50];  // 定义一个最多存储100本图书信息的数组
    int count = 0;  // 图书数量
    readInfoFromFile(books, &count);
    int option;
    do {
        printf("\n\n*********************【图书信息管理系统】张三，20822XXXX *********************\n");
        printf("**********            1：录入图书信息       **********\n");
        printf("**********            2：浏览图书信息       **********\n");
        printf("**********            3：查询图书信息       **********\n");
        printf("**********            4：删除图书信息       **********\n");
        printf("**********            5：修改图书信息       **********\n");
        printf("**********            0：保存并退出系统       **********\n");
        printf("请输入需要进行的操作序号：");
        scanf("%d", &option);

        switch (option) {
        case 1:
            inputInfo(books, &count);
            break;
        case 2:
            browseInfo(books, count);
            break;
        case 3:
            searchInfo(books, count);
            break;
        case 4:
            deleteInfo(books, &count);
            break;
        case 5:
            modifyInfo(books, count);
            break;
        case 0:
            saveInfoToFile(books, count);
            printf("数据已保存，感谢使用！\n");
            break;
        default:
            printf("无效的操作序号，请重新输入。\n");
            break;
        }
    } while (option != 0);

    return 0;
}

void readInfoFromFile(struct BookInfo* books, int* count) {
    FILE* file = fopen("books.dat", "rb");
    if (file == NULL) {
        printf("无法打开文件！\n");
        return;
    }

    *count = 0;
    while (*count < 50 && fread(&books[*count], sizeof(struct BookInfo), 1, file) == 1) {
        (*count)++;
    }

    fclose(file);
}

void saveInfoToFile(const struct BookInfo* books, int count) {
    FILE* file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("无法打开文件！\n");
        return;
    }

    fwrite(books, sizeof(struct BookInfo), count, file);

    fclose(file);
}

// 输入图书信息
void inputInfo(struct BookInfo* books, int* count) {
    struct BookInfo newBook;

    printf("请输入图书分类号：");
    scanf("%s", newBook.category);
    printf("请输入图书书名：");
    scanf("%s", newBook.title);
    printf("请输入图书编者：");
    scanf("%s", newBook.author);
    printf("请输入图书出版社：");
    scanf("%s", newBook.publisher);
    printf("请输入图书出版年月：");
    scanf("%s", newBook.publish_date);
    printf("请输入图书价格：");
    scanf("%f", &newBook.price);

    books[*count] = newBook;
    (*count)++;

    printf("图书信息已录入！\n");
}

// 浏览图书信息
void browseInfo(const struct BookInfo* books, int count) {
    if (count == 0) {
        printf("暂无图书信息。\n");
        return;
    }

    printf("图书信息如下：\n");
    for (int i = 0; i < count; i++) {
        printf("**************************\n");
        printf("分类号：%s\n", books[i].category);
        printf("书名：%s\n", books[i].title);
        printf("编者：%s\n", books[i].author);
        printf("出版社：%s\n", books[i].publisher);
        printf("出版年月：%s\n", books[i].publish_date);
        printf("价格：%.2f\n", books[i].price);
        printf("**************************\n");
    }
}

// 查询图书信息
void searchInfo(const struct BookInfo* books, int count) {
    if (count == 0) {
        printf("暂无图书信息。\n");
        return;
    }

    int option;
    printf("请选择查询方式：\n");
    printf("1. 按分类号查询\n");
    printf("2. 按书名查询\n");
    printf("3. 按作者查询\n");
    printf("4. 按出版社查询\n");
    printf("请输入选项：");
    scanf("%d", &option);

    char keyword[50];
    printf("请输入查询关键字：");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (option == 1 && strcmp(books[i].category, keyword) == 0) {
            printf("**************************\n");
            printf("分类号：%s\n", books[i].category);
            printf("书名：%s\n", books[i].title);
            printf("编者：%s\n", books[i].author);
            printf("出版社：%s\n", books[i].publisher);
            printf("出版年月：%s\n", books[i].publish_date);
            printf("价格：%.2f\n", books[i].price);
            printf("**************************\n");
            found = 1;
        }
        else if (option == 2 && strcmp(books[i].title, keyword) == 0) {
            printf("**************************\n");
            printf("分类号：%s\n", books[i].category);
            printf("书名：%s\n", books[i].title);
            printf("编者：%s\n", books[i].author);
            printf("出版社：%s\n", books[i].publisher);
            printf("出版年月：%s\n", books[i].publish_date);
            printf("价格：%.2f\n", books[i].price);
            printf("**************************\n");
            found = 1;
        }
        else if (option == 3 && strcmp(books[i].author, keyword) == 0) {
            printf("**************************\n");
            printf("分类号：%s\n", books[i].category);
            printf("书名：%s\n", books[i].title);
            printf("编者：%s\n", books[i].author);
            printf("出版社：%s\n", books[i].publisher);
            printf("出版年月：%s\n", books[i].publish_date);
            printf("价格：%.2f\n", books[i].price);
            printf("**************************\n");
            found = 1;
        }
        else if (option == 4 && strcmp(books[i].publisher, keyword) == 0) {
            printf("**************************\n");
            printf("分类号：%s\n", books[i].category);
            printf("书名：%s\n", books[i].title);
            printf("编者：%s\n", books[i].author);
            printf("出版社：%s\n", books[i].publisher);
            printf("出版年月：%s\n", books[i].publish_date);
            printf("价格：%.2f\n", books[i].price);
            printf("**************************\n");
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的图书信息。\n");
    }
}

// 删除图书信息
void deleteInfo(struct BookInfo* books, int* count) {
    if (*count == 0) {
        printf("暂无图书信息。\n");
        return;
    }

    char keyword[50];
    printf("请输入要删除的图书书名：");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].title, keyword) == 0) {
            found = 1;

            // 将最后一本图书信息覆盖到要删除的位置
            books[i] = books[*count - 1];
            (*count)--;
            printf("图书信息已删除！\n");
            break;
        }
    }

    if (!found) {
        printf("未找到要删除的图书信息。\n");
    }
}

// 修改图书信息
void modifyInfo(struct BookInfo* books, int count) {
    if (count == 0) {
        printf("暂无图书信息。\n");
        return;
    }

    char keyword[50];
    printf("请输入要修改的图书书名：");
    scanf("%49s", keyword);  // 限制输入的字符串长度为49个字符

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, keyword) == 0) {
            found = 1;

            struct BookInfo newBook;
            printf("请输入新的图书分类号：");
            scanf("%19s", newBook.category);  // 限制输入的字符串长度为19个字符
            printf("请输入新的图书书名：");
            scanf("%49s", newBook.title);  // 限制输入的字符串长度为49个字符
            printf("请输入新的图书编者：");
            scanf("%29s", newBook.author);  // 限制输入的字符串长度为29个字符
            printf("请输入新的图书出版社：");
            scanf("%49s", newBook.publisher);  // 限制输入的字符串长度为49个字符
            printf("请输入新的图书出版年月：");
            scanf("%19s", newBook.publish_date);  // 限制输入的字符串长度为19个字符
            printf("请输入新的图书价格：");
            scanf("%f", &newBook.price);

            books[i] = newBook;
            printf("图书信息已修改！\n");
            break;
        }
    }

    if (!found) {
        printf("未找到要修改的图书信息。\n");
    }
}
