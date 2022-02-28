#include <stdio.h>
#include "main.h"

static void getName(Apple _this)
{
  printf(_this.name);
}

static void getNameTwo(Apple _this)
{
  printf("%s %s %s", _this.name, "But Better", _this.grade);
}

classimpl(Apple, Apple,
          .getName = &getName); // implements the class

classimpl(BetterApple, Apple,
          .getName = &getNameTwo); // implements the same class?, kindof like interface

Apple iApple = {withClass(BetterApple), .name = "Better one", .grade = "Nice one"};

int main(void)
{
  getClass(Apple, iApple)->getName(iApple);
}