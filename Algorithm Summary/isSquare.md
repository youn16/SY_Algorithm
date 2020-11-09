# 제곱수인지 확인하는 함수

## cpp 버전
> include <math.h>가 필요

```cpp
#include <math.h>

bool isSquare(int a){
    unsigned int tmp = (unsigned int)(sqrt((double)a))+0.5;
    return tmp*tmp == a;
}
```