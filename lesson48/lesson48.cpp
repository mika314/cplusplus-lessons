// Урок 48
// Загадка Эйнштейна
#include <iostream>
using namespace std;

enum { _ = 5 };
enum { Red, Green, Yellow, Blue, White };
const char *ColorStr[] = { "красный", "зеленый", "желтый", "синий", "белый", "-" };
enum { Tea, Milk, Water, Beer, Coffee };
const char *DrinkStr[] = { "чай", "молоко", "вода", "пиво", "кофе", "-" };
enum { Cat, Bird, Dog, Horse, Fish };
const char *PetStr[] = { "кошки", "птицы", "собаки", "лошади", "рыбки", "-" };
enum { Rothmans, Dunhill, Marlboro, PallMall, Winfield };
const char *CigarettesStr[] = { "Rothmans", "Dunhill", "Marlboro", "Pall Mall", "Winfield", "-" };
enum { Norwegian, Englishman, Dane, German, Swede };
const char *NationalityStr[] = { "норвежец", "англичанин", "датчанин", "немец", "швед", "-" };
enum Property { Color, Drink, Pet, Cigarettes, Nationality, PropertiesCount };

// На одной улице подряд стоят пять домов, 
const size_t HousesCount = 5;

int s[HousesCount][PropertiesCount];

bool neighborOf(size_t i, int property, int value)
{
  return (i >= 1 && (s[i - 1][property] == _ || s[i - 1][property] == value)) ||
    (i < HousesCount - 1 && (s[i + 1][property] == _ || s[i + 1][property] == value));
}

bool check()
{
  // каждый — своего цвета. В каждом живёт человек, все пять — разных национальностей. 
  // Каждый человек предпочитает уникальную марку сигарет, напиток и домашнее животное. 
  for (size_t i = 0; i < HousesCount; ++i)
  {
    for (size_t j = 0; j < PropertiesCount; ++j)
    {
      int &p1 = s[i][j];
      for (size_t k = i + 1; k < HousesCount; ++k)
      {
        int &p2 = s[k][j];
        if (p1 != _ && p2 != _ && p1 == p2)
          return false;
      }
    }
  }

  // Кроме того:
  // Норвежец живёт в первом доме.
  if (s[0][Nationality] != Norwegian && s[0][Nationality] != _)
    return false;
  // Англичанин живёт в красном доме.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Englishman && s[i][Color] != _ && s[i][Color] != Red)
      return false;
  // Зелёный дом находится слева от белого, рядом с ним.
  for (size_t i = 0; i < HousesCount - 1; ++i)
    if (s[i][Color] == Green && s[i + 1][Color] != _ && s[i + 1][Color] != White)
      return false;
  // Датчанин пьёт чай.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Dane && s[i][Drink] != _ && s[i][Drink] != Tea)
      return false;
  // Тот, кто курит Marlboro, живёт рядом с тем, кто выращивает кошек.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Cigarettes] == Marlboro && !neighborOf(i, Pet, Cat))
      return false;
// Тот, кто живёт в жёлтом доме, курит Dunhill.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Color] == Yellow && s[i][Cigarettes] != _ && s[i][Cigarettes] != Dunhill)
      return false;
// Немец курит Rothmans.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == German && s[i][Cigarettes] != _ && s[i][Cigarettes] != Rothmans)
      return false;
// Тот, кто живёт в центре, пьёт молоко.
  if (s[2][Drink] != _ && s[2][Drink] != Milk)
    return false;
// Сосед того, кто курит Marlboro, пьёт воду.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Cigarettes] == Marlboro && !neighborOf(i, Drink, Water))
      return false;
// Тот, кто курит Pall Mall, выращивает птиц.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Cigarettes] == PallMall && s[i][Pet] != _ && s[i][Pet] != Bird)
      return false;
// Швед выращивает собак.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Swede && s[i][Pet] != _ && s[i][Pet] != Dog)
      return false;
// Норвежец живёт рядом с синим домом.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Norwegian && !neighborOf(i, Color, Blue))
      return false;
// Тот, кто выращивает лошадей, живёт в синем доме.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Pet] == Horse && s[i][Color] != _ && s[i][Color] != Blue)
      return false;
// Тот, кто курит Winfield, пьет пиво.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Cigarettes] == Winfield && s[i][Drink] != _ && s[i][Drink] != Beer)
      return false;
// В зелёном доме пьют кофе.
  for (size_t i = 0; i < HousesCount; ++i)
    if (s[i][Color] == Green && s[i][Drink] != _ && s[i][Drink] != Coffee)
      return false;
// Вопрос:
// Кто разводит рыбок?
  return true;
}

bool findSolution(int y, int x)
{
  int tmp = s[y][x];
  for (int i = 0; i < 5; ++i)
  {
    s[y][x] = i;
    if (check())
    {
      const size_t newX = (x + 1) % PropertiesCount;
      const size_t newY = y + (newX != 0 ? 0 : 1);
      if (newY >= HousesCount || findSolution(newY, newX))
        return true;
    }
  }
  s[y][x] = tmp;
  return false;
}

void print()
{
  for (size_t i = 0; i < HousesCount; ++i)
  {
    cout << i + 1 << " " <<
      ColorStr[s[i][Color]] << " "  <<
      DrinkStr[s[i][Drink]] << " "  <<
      PetStr[s[i][Pet]] << " "  <<
      CigarettesStr[s[i][Cigarettes]] << " "  <<
      NationalityStr[s[i][Nationality]] << " "  <<
      endl;
  }
}

int main()
{
  for (size_t i = 0; i < HousesCount; ++i)
    for (size_t j = 0; j < PropertiesCount; ++j)
      s[i][j] = _;
  if (findSolution(0, 0))
    print();
  else
    cout << "Решение не найдено." << endl;
}
