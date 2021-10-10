# CLang Learning Following Bilibili Video

## Notes

### Data Type

The size of type is different between 32bit and 64bit, even different between complier. Call `sizeof(int)` got the real size of `int`

|       Type       |    Size    |                        Range                         |
| :--------------: | :--------: | :--------------------------------------------------: |
|      `char`      |   1byte    |               -128 to 127 or 0 to 255                |
| `unsigned char`  |   1byte    |                     -128 to 127                      |
|  `signed char`   |   1byte    |                       0 to 255                       |
|      `int`       | 2 or 4byte | -32,768 to 32,767 ro -2,147,483,648 to 2,147,483,647 |
|  `unsigned int`  | 2 or 4byte |          0 to 65,535 or 0 to 4,294,967,295           |
|     `short`      |   2byte    |                  -32,768 to 32,767                   |
| `unsigned short` |   2byte    |                     0 to 65,535                      |
|      `long`      |   4byte    |           -2,147,483,648 to 2,147,483,647            |
| `unsigned long`  |   4byte    |                  0 to 4,294,967,295                  |
|     `float`      |     -      |                          -                           |
|     `double`     |     -      |                          -                           |
|   `long long`    |     -      |                          -                           |

### Variable

- global variable - define outside of function scope.
- local variable - define in a function.
- variable scope - range that can access variable.
- local variable priority over global variable.

### Constant Variable

- literal
- `const` defined
- `enum` defined
- `#define`

```c
#define MAX 1000 // #define

enum Sex {
    MALE, // enum constant variable
    FEMALE,
    SECRET
}

int main()
{
    "3.14"; // literal constant variable
    const int a = 1; // `const`
}
```
