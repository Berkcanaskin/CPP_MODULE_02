# CPP Module 02 - Ad Hoc Polymorphism, Operatör Overloading ve Canonical Form

## 📚 Proje Açıklaması

CPP Module 02, C++'da operatör overloading, ad hoc polymorphism ve Orthodox Canonical Form gibi ileri OOP konseptlerini kapsayan eğitim projesidir.

## 🎯 Modülde Bulunan Egzersizler

### Exercise 00: My First Class in Orthodox Canonical Form
**Amaç:** Orthodox Canonical Form'ın nasıl uygulanacağını öğrenmek

**Neler Öğrenildi:**
- Default constructor
- Copy constructor
- Copy assignment operator (=)
- Destructor
- The Rule of Five (C++11+)

**Yapı:**
```cpp
class Fixed {
private:
    int _value;
public:
    Fixed();                           // Default constructor
    Fixed(const Fixed &other);         // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment
    ~Fixed();                          // Destructor
};
```

### Exercise 01: Towards a more useful fixed-point number
**Amaç:** Fixed-point sayı sınıfı oluşturma ve operatör overloading

**Neler Öğrenildi:**
- Operatör overloading (`<<`, `>>`)
- Member fonksiyonlar
- Getter ve setter metodlar
- Int ve float conversion'ları

**Operatörler:**
- `<<` (insertion operator)
- `>>` (extraction operator)
- Conversion konstruktörleri

### Exercise 02: Now we're talking
**Amaç:** Karşılaştırma ve aritmetik operatörleri overload etme

**Neler Öğrenildi:**
- Karşılaştırma operatörleri (`<`, `>`, `<=`, `>=`, `==`, `!=`)
- Aritmetik operatörleri (`+`, `-`, `*`, `/`)
- Pre ve post increment/decrement (`++i`, `i++`)
- Min ve max fonksiyonları

## 🛠️ Kullanım

```bash
cd CPP_MODULE_02/ex00
make
./fixed
```

## 📖 Temel C++ Kavramları

### Orthodox Canonical Form (Coplien Form)
```cpp
class MyClass {
private:
    int value;

public:
    MyClass();                           // Default constructor
    MyClass(const MyClass &other);       // Copy constructor
    MyClass &operator=(const MyClass &other); // Copy assignment
    ~MyClass();                          // Destructor
};
```

### Operatör Overloading Türleri

**Member Functions:**
```cpp
Fixed operator+(const Fixed &other) const;
Fixed &operator++();  // Pre-increment
Fixed operator++(int); // Post-increment
```

**Non-Member Functions:**
```cpp
std::ostream &operator<<(std::ostream &os, const Fixed &f);
```

### Fixed-Point Sayılar
- Integer kısmı ve fractional kısmı olan sayılar
- Floating-point'ten daha hassas işlemler
- Embedded systems'de yaygın kullanım

## 📚 Öğrenme Çıktıları

✅ Orthodox Canonical Form mastered  
✅ Operatör overloading anlaşıldı  
✅ Fixed-point sayı aritmetiği öğrenildi  
✅ Member ve non-member operatörler pratiği yapıldı  
✅ Conversion operatörleri anlaşıldı  

## 🔧 Makefile

```bash
make         # Derleme
make clean   # Object dosyaları sil
make fclean  # Tüm dosyaları sil
make re      # Yeniden derleme
```

## 📝 Notlar

- Coplien Form (Orthodox Canonical Form) kesinlikle uygulanmıştır
- Const correctness göz önüne alınmıştır
- Member initializer list kullanılmıştır
- Memory leaks mevcut değildir

## Faydalı Linkler

- [Orthodox Canonical Form](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-copyable_Mixin)
- [Operator Overloading in C++](https://en.cppreference.com/w/cpp/language/operators)
