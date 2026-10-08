#include <clocale>
#include <ctime>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

const int kSentinel = INT_MIN;

// ============================================================
//                     ПРОТОТИПЫ
// ============================================================

// --- Утилиты ---
std::string TaskNumber(int choice);
void Pause();
void PrintSeparator();
void ClearInput();
int ArrayLength(int arr[]);
int ReadInt(const std::string& prompt);
bool ReadArray(std::vector<int>& v);
void RunTask(int choice);

// --- Интерфейс ---
void PrintHeader();
void PrintMenu();
void PrintTaskTitle(const std::string& task_number);

// --- Задачки ---
int SumLastNums(int x);
bool IsPositive(int x);
bool IsUpperCase(char x);
bool IsDivisor(int a, int b);
int LastNumSum(int a, int b);
double SafeDiv(int x, int y);
std::string MakeDecision(int x, int y);
bool Sum3(int x, int y, int z);
std::string Age(int x);
void PrintDays(int x);
std::string ReverseListNums(int x);
int Pow(int x, int y);
bool EqualNum(int x);
void LeftTriangle(int x);
void GuessGame();
int FindLast(int arr[], int x);
int* Add(int arr[], int x, int pos);
void Reverse(int arr[]);
int* Concat(int arr1[], int arr2[]);
int* DeleteNegative(int arr[]);

// ============================================================
//                       MAIN
// ============================================================

int main() {
  setlocale(LC_ALL, "RU");
  PrintHeader();

  while (true) {
    PrintMenu();
    int choice;
    do {
      choice = ReadInt("Ввод: ");
      if (choice < 0 || choice > 20) {
        std::cout << "Доступны только команды от 0 до 20, попробуй ещё раз.\n";
      }
    } while (choice < 0 || choice > 20);

    if (choice == 0) {
      std::cout << "Завершение работы программы...\n";
      return 0;
    }

    PrintTaskTitle(TaskNumber(choice));
    RunTask(choice);
    Pause();
  }
}

// ============================================================
//                      УТИЛИТЫ
// ============================================================

std::string TaskNumber(int choice) {
  int major = (choice - 1) / 5 + 1;
  int minor = ((choice - 1) % 5) * 2 + 2;
  return std::to_string(major) + "." + std::to_string(minor);
}

void Pause() {
  std::cout << "(Enter)" << std::flush;
  std::string temp;
  std::getline(std::cin, temp);
}

void PrintSeparator() {
  std::cout << "---------------------------------------------------------------------------\n";  // 75
}

void ClearInput() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

int ArrayLength(int arr[]) {
  int n = 0;
  while (arr[n] != kSentinel) ++n;
  return n;
}

int ReadInt(const std::string& prompt) {
  int value;
  std::cout << prompt;
  while (!(std::cin >> value)) {
    std::cin.clear();
    ClearInput();
    std::cout << "Не число, попробуй ещё: ";
  }
  ClearInput();
  return value;
}

bool ReadArray(std::vector<int>& v) {
  v.clear();
  std::string line;
  std::cout << "Введите массив (через пробел):\n";
  std::getline(std::cin, line);
  std::istringstream iss(line);
  int value;
  while (iss >> value) {
    v.push_back(value);
  }

  if (!iss.eof()) {
    return false;
  }

  v.push_back(kSentinel);
  return true;
}

void RunTask(int choice) {
  switch (choice) {
    case 1: {
      int x = ReadInt("Введите число: ");
      int result = SumLastNums(x);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 2: {
      int x = ReadInt("Введите число: ");
      bool result = IsPositive(x);
      if (result == 0) {
        std::cout << "Результат: False\n";
      } else {
        std::cout << "Результат: True\n";
      }
      break;
    }
    case 3: {
      char symbol;

      std::cout << "Введите символ: ";
      std::cin >> symbol;
      ClearInput();

      bool result = IsUpperCase(symbol);

      if (result == 0) {
        std::cout << "Результат: False\n";
      } else {
        std::cout << "Результат: True\n";
      }
      break;
    }
    case 4: {
      int a = ReadInt("Введите первое число: ");
      int b = ReadInt("Введите второе число: ");
      bool result = IsDivisor(a, b);
      if (result == 0) {
        std::cout << "Результат: False\n";
      } else {
        std::cout << "Результат: True\n";
      }
      break;
    }
    case 5: {
      for (int i = 1; i < 6; ++i) {
        std::cout << "--------------------------------- " << i << " из 5 ----------------------------------\n";
        int a = ReadInt("Введите первое число: ");
        int b = ReadInt("Введите второе число: ");
        int result = LastNumSum(a, b);
        std::cout << "Результат: " << result << "\n";
        if (i != 5) {
          Pause();
        }
      }
      break;
    }
    case 6: {
      int x = ReadInt("Введите числитель: ");
      int y = ReadInt("Введите знаменатель: ");
      double result = SafeDiv(x, y);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 7: {
      int x = ReadInt("Введите первое число: ");
      int y = ReadInt("Введите второе число: ");
      std::string result = MakeDecision(x, y);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 8: {
      int x = ReadInt("Введите первое число: ");
      int y = ReadInt("Введите второе число: ");
      int z = ReadInt("Введите третее число: ");
      bool result = Sum3(x, y, z);
      if (result == 0) {
        std::cout << "Результат: False\n";
      } else {
        std::cout << "Результат: True\n";
      }
      break;
    }
    case 9: {
      int x = ReadInt("Введите число: ");
      std::string result = Age(x);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 10: {
      int x = ReadInt("Введите число: ");
      PrintDays(x);
      break;
    }
    case 11: {
      int x = ReadInt("Введите число: ");
      std::string result = ReverseListNums(x);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 12: {
      int x = ReadInt("Введите число: ");
      int y = ReadInt("Введите степень: ");
      if (y < 0) {
        std::cout << "Программа не предусмотрена для отрицательных степеней.\n";
        break;
      }
      int result = Pow(x, y);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 13: {
      int x = ReadInt("Введите число: ");
      bool result = EqualNum(x);
      if (result == 0) {
        std::cout << "Результат: False\n";
      } else {
        std::cout << "Результат: True\n";
      }
      break;
    }
    case 14: {
      int x = ReadInt("Введите число: ");
      std::cout << "Результат: \n";
      LeftTriangle(x);
      break;
    }
    case 15: GuessGame(); break;
    case 16: {
      std::vector<int> v;
      if (!ReadArray(v)) {
        std::cout << "Ошибка: в строке есть нечисловой элемент.\n";
        break;
      }
      int x = ReadInt("Введите число x: ");
      int result = FindLast(v.data(), x);
      std::cout << "Результат: " << result << "\n";
      break;
    }
    case 17: {
      std::vector<int> v;
      if (!ReadArray(v)) {
        std::cout << "Ошибка: в строке есть нечисловой элемент.\n";
        break;
      }
      int x = ReadInt("Введите x: ");
      int pos = ReadInt("Введите pos: ");
      int n = ArrayLength(v.data());
      if (pos < 0 || pos > n) {
        std::cout << "Ошибка: позиция " << pos << " вне диапазона [0, " << n << "]\n";
        break;
      }
      int* result = Add(v.data(), x, pos);

      std::cout << "Результат: ";
      for (int i = 0; result[i] != kSentinel; ++i) {
        std::cout << result[i] << " ";
      }
      std::cout << "\n";

      delete[] result;
      break;
    }
    case 18: {
      std::vector<int> v;
      if (!ReadArray(v)) {
        std::cout << "Ошибка: в строке есть нечисловой элемент\n";
        break;
      }
      Reverse(v.data());
      std::cout << "Результат: ";
      for (int i = 0; v[i] != kSentinel; ++i) {
        std::cout << v[i] << " ";
      }
      std::cout << "\n";
      break;
    }
    case 19: {
      std::vector<int> v1;
      if (!ReadArray(v1)) {
        std::cout << "Ошибка: в первом массиве есть нечисловой элемент\n";
        break;
      }

      std::vector<int> v2;
      if (!ReadArray(v2)) {
        std::cout << "Ошибка: во втором массиве есть нечисловой элемент\n";
        break;
      }

      int* result = Concat(v1.data(), v2.data());

      std::cout << "Результат: ";
      for (int i = 0; result[i] != kSentinel; ++i) {
        std::cout << result[i] << " ";
      }
      std::cout << "\n";

      delete[] result;
      break;
    }
    case 20: {
      std::vector<int> v;
      if (!ReadArray(v)) {
        std::cout << "Ошибка: в строке есть нечисловой элемент\n";
        break;
      }

      int* result = DeleteNegative(v.data());

      std::cout << "Результат: ";
      for (int i = 0; result[i] != kSentinel; ++i) {
        std::cout << result[i] << " ";
      }
      std::cout << "\n";

      delete[] result;
      break;
    }
  }
}

// ============================================================
//                     ИНТЕРФЕЙС
// ============================================================

void PrintHeader() {
  PrintSeparator();
  std::cout << "------------------------- Лабораторная работа №1 --------------------------\n";
  PrintSeparator();
}

void PrintMenu() {
  std::cout << "------------------------------ Главное меню -------------------------------\n";
  std::cout << " 1. \"1.2\"        2. \"1.4\"        3. \"1.6\"        4. \"1.8\"        5.  \"1.10\" \n";
  std::cout << " 6. \"2.2\"        7. \"2.4\"        8. \"2.6\"        9. \"2.8\"       10.  \"2.10\" \n";
  std::cout << "11. \"3.2\"       12. \"3.4\"       13. \"3.6\"       14. \"3.8\"       15.  \"3.10\" \n";
  std::cout << "16. \"4.2\"       17. \"4.4\"       18. \"4.6\"       19. \"4.8\"       20.  \"4.10\" \n";
  std::cout << "0.  Выход\n";
  PrintSeparator();
}

void PrintTaskTitle(const std::string& task_number) {
  PrintSeparator();
  std::cout << "Задача " << task_number << "\n";
  PrintSeparator();
}

// ============================================================
//                      ЗАДАЧИ
// ============================================================
// --- 1.2 ---
int SumLastNums(int x) {
  if (x < 0) {
    x = -x;
  }
  int last = x % 10;
  int pre_last = (x / 10) % 10;
  return last + pre_last;
}
// --- 1.4 ---
bool IsPositive(int x) { return x > 0; }
// --- 1.6 ---
bool IsUpperCase(char x) { return x >= 'A' && x <= 'Z'; }
// --- 1.8 ---
bool IsDivisor(int a, int b) { return (a % b == 0) || (b % a == 0); }
// --- 1.10 ---
int LastNumSum(int a, int b) {
  if (a < 0) {
    a = -a;
  }
  if (b < 0) {
    b = -b;
  }
  return a % 10 + b % 10;
}

// --- 2.2 ---
double SafeDiv(int x, int y) {
  if (y == 0) {
    return 0;
  }
  return static_cast<double>(x) / y;
}
// --- 2.4 ---
std::string MakeDecision(int x, int y) {
  if (x > y) {
    return std::to_string(x) + " > " + std::to_string(y);
  } else if (x < y) {
    return std::to_string(x) + " < " + std::to_string(y);
  } else
    return std::to_string(x) + " == " + std::to_string(y);
}
// --- 2.6 ---
bool Sum3(int x, int y, int z) { return (x + y == z) || (x + z == y) || (y + z == x); }
// --- 2.8 ---
std::string Age(int x) {
  if (x < 0) {
    return "Возраст не может быть < 0";
  }

  if (x % 100 >= 11 && x % 100 <= 14) {
    return std::to_string(x) + " лет";
  }

  switch (x % 10) {
    case 1: return std::to_string(x) + " год";
    case 2:
    case 3:
    case 4: return std::to_string(x) + " года";
    default: return std::to_string(x) + " лет";
  }
}
// --- 2.10 ---
void PrintDays(int x) {
  switch (x) {
    case 1: std::cout << "Понедельник\n";
    case 2: std::cout << "Вторник\n";
    case 3: std::cout << "Среда\n";
    case 4: std::cout << "Четверг\n";
    case 5: std::cout << "Пятница\n";
    case 6: std::cout << "Суббота\n";
    case 7: std::cout << "Воскресенье\n"; break;
    default: std::cout << "Это не день недели!\n";
  }
}

// --- 3.2 ---
std::string ReverseListNums(int x) {
  std::string result = std::to_string(x);
  int step;
  if (x > 0) {
    step = -1;
    x = x - 1;
  } else if (x < 0) {
    step = 1;
    x = x + 1;
  } else {
    return result;
  }
  for (int i = x;; i += step) {
    result += " " + std::to_string(i);
    if (i == 0) break;
  }
  return result;
}
// --- 3.4 ---
int Pow(int x, int y) {
  int result = 1;
  for (int i = 0; i < y; ++i) {
    result *= x;
  }
  return result;
}
// --- 3.6 ---
bool EqualNum(int x) {
  int last = x % 10;
  x /= 10;
  while (x) {
    if (x % 10 != last) {
      return false;
    }
    x /= 10;
  }
  return true;
}
// --- 3.8 ---
void LeftTriangle(int x) {
  if (x < 1) {
    std::cout << "Недостаточно звезд для треугольника.\n";
  }
  std::string stars = "*";
  for (int i = 0; i < x; ++i) {
    std::cout << stars << "\n";
    stars += "*";
  }
}
// --- 3.10 ---
void GuessGame() {
  std::srand(std::time(0));
  int number = std::rand() % 10;
  int counter = 1;
  int attempt = ReadInt("Введите число от 0 до 9: ");
  while (attempt != number) {
    attempt = ReadInt("Неверно, попробуй еще раз: ");
    counter++;
  }
  std::cout << "Вы отгадали с " << counter << " попытки\n";
}

// --- 4.2 ---
int FindLast(int arr[], int x) {
  int result = -1;
  int i = 0;
  while (arr[i] != kSentinel) {
    if (arr[i] == x) {
      result = i;
    }
    ++i;
  }
  return result;
}
// --- 4.4 ---
int* Add(int arr[], int x, int pos) {
  int n = ArrayLength(arr);

  int* result = new int[n + 2];

  for (int i = 0; i < pos; ++i) {
    result[i] = arr[i];
  }

  result[pos] = x;

  for (int i = pos; i < n; ++i) {
    result[i + 1] = arr[i];
  }

  result[n + 1] = kSentinel;

  return result;
}
// --- 4.6 ---
void Reverse(int arr[]) {
  int n = ArrayLength(arr);

  for (int i = 0; i < n / 2; ++i) {
    int temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
  }
}
// --- 4.8 ---
int* Concat(int arr1[], int arr2[]) {
  int n1 = ArrayLength(arr1);
  int n2 = ArrayLength(arr2);
  int n = n1 + n2;
  int* result = new int[n + 1];
  for (int i = 0; i < n1; ++i) {
    result[i] = arr1[i];
  }
  for (int i = 0; i < n2; ++i) {
    result[n1 + i] = arr2[i];
  }
  result[n] = kSentinel;
  return result;
}
// --- 4.10 ---
int* DeleteNegative(int arr[]) {
  int n = ArrayLength(arr);

  int* result = new int[n + 1];
  int count_positive = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] >= 0) {
      result[count_positive++] = arr[i];
    }
  }

  result[count_positive] = kSentinel;

  return result;
}