Объявление, опеределение, инициализация, присваивание

0x....123 mod size = 0

## Выравнивание данных

	struct arr {  
		char c; // 1 byte  
		struct arr *p; // 8 bytes x64  
		short x; // 2 bytes  
	}

	struct arr {
		char c;      
		char pad0[7]; //8 bytes
		struct arr *p;  //8 bytes
		short x;      
		char pad1[6]; //8 bytes
	}
сначала длинные, потом короткие!

### Встроенные методы:
- указатели -> smart pointers  <- стандартная библиотека STL\
- массивы дин, стат    	new [] 		-> контейнеры 

# Указатели
T* - тип указателя на тип T

	char c = 'a';
	char* ptr = &c; // взятие адреса
	char c2 = *ptr; // разыменование

void* - такое тоже есть

nullptr - понятно

## Массивы

	int arr[size];
	int arr[] = {1, 2, 3, 4};

	int* p = arr; // указатель на 0й элемент
	p++; // указатель на 1й

	const int a = 10; // константа
указатель не может быть константой, за исключением случая, когда мы\ ссылаемся на константу\
const int* p = &a;

## Выделение памяти
new - создает динамическую ячейку памяти под некоторый объект\
delete - освобождает память\
alloc, calloc, malloc\
new int arr - например

## Многомерные массивы
int d1 = 3, d2 = 5;

	int arr[d1][d2] = 
		{	},
		{	},
		{	}; // статический двумерный массив

динамический массив - массив указателей на одномерные массивы

## Строки
	char str[4][3] = {'ab', 'a', 'b', 'ba'}; // в конце идет \0

# Про функции
Чтобы передать массив в функцию, нужно передать указатель на него\
int f(int ... ) const - функция не меняет аргументы

## Объявление

	int func(); // объявление
	int func() {
		...
	} // определение
Использовать функции с объявлением удобно при экспорте

## inline функции
	int quod(int a) {return pow(a, 4)}

Компилятор обращается с такими функциями более оптимально

	inline int ... {
		...
	} // если не уместилось в строку

__force inline ... - заставить компилятор

## auto функции

	auto f(){...};

Так автоматически поределяется тип возвращаемого значения

Полезно если функция может вернуть и int, и float

## Аргументы по умолчанию

Писать после аргументов без умолчания

## Лямбда функция

Обрабатывается компилятором как вставка кода, без выделения отдельной памяти в другом месте 

	int L = [](){};
Или

	std::function <> f = {};

Пример

	auto foo = [&x, &y](int p){x += p; y += p};
	int x = 1, y = 1;
	foo(2); // станет x = y = p

## Перегрузка функциями

	int print(char c) {
		cout << (int) c;
	}

	int print(int a) {
		cout << a;
	}

# Синтаксические приколы

## Унарные операторы

### Инкрементация

++i - префиксная, i++ - постфиксная

	int b = 1;
	a = 5* ++b; // a = 10, b = 2
	c = 5* b++; // a = 5, b = 2

НО! 

	int x = 0;
	a = ++x + ++x; // a = 4!

### Декрементация - аналогично

## Тернарный оператор

i ? j : k

i - bool, если true, то возвращается j, иначе k

std::cout << true ? 9 : '9' << ' ' << false ? 9 : '9'; - вывод будет "9 57", потому что тернарный оператор приводит типы к одному

	int a = 1, b = 1, c = 1;
	a = true ? ++b : ++c; // будет a = b = 2, c = 1


	true ? a : b = 10; // в a присвоится 10 (если a и b инты, если a int, b float, то будет ошибка)

# Переменные

## Глобальные и локальные

int value = 1;

	int func() {
		int value = 2;
		return value;
	} // вернет 2

Если написать return::value, то вернется 1 (:: - обращение к глобальным)

Или:

	int value1 = 1;
	...
		return value1;

перед глобальной переменной принято писать static

	static int value = 1;

## Приведение типов

	char a = '9';
	b = (int) c; // b будет 57

## Константы

Из не константы сделать константу можно, наоборот -- нет!

# Структуры

	struct person {
		std::string name;
		unsigned short int;
		int salary;
	}

	person p {"Klim", 23}; // {"Klim", 23} называется агрегатом
	p.age = 24;

	person* ptr = &p;
	ptr->name = "Maxim"; // то же что (*ptr).name =...

## Списки инициализации

	person(...): name(n), age(14), ...; // конструктор структуры

### Конструктор:

1. Выделяет ресурсы и инициализирует данные
2. Выполняет тело конструктора

### Деструктор
1. Выполняет тело
2. Освобождает память (удаляет данные)

Теоретически *можно* добавлять функцию в структуру, но **не нужно**

## Микрооптимизация памяти

	struct person {
		std::string name : 5 ;
		unsigned short int : 7;
		int salary : ...;
	} // через двоеточие можно указывать 
	//конкретный размер памяти под поле

Пример принципа RAII

## Enumeration

	enum[class] colors {
		"red", // = 0
		"green", // = 0
		"blue" // = 0
	} // class - тип объектов внутри (в данном случае string)

# Память

## Статическая

Выделяется на **стеке**

### Стек вызовов

	int main(int argc, char** argv)

argc - количество аргументов с консоли

argv - сами аргументы в виде строк

Функции на стеке хранятся как указатели на участки кода

	setrlimit(name, value1, value2) // устанавливает ограничение на объем стека


## Динамическая

Работает как **куча**, медленней чем статическая

## Аналогии с C

### Выделение / освобождение памяти

	С				С++
	malloc			new
	calloc			new[]
	realloc			delete
	free			delete[]

**new**, в отличии от **malloc** сразу вызывает конструктор и создает объект

### Ввод / Вывод

	C				C++
	scanf()			std::cin
	printf()		std::cout

**scanf** и **printf** - функции, работающие со строками

**std::cin** и **std::cout** - объекты потокового типа

**<<**, **>>** - объекты

Сишные функции быстрее!

### Строки

	C				C++
	"adc\0"			std::string

В Си строки это массивы charов с символом '\0' на конце

В плюсах это объект избавленный от неудобств Си

# Классы

## Парадигмы ООП

1. ### Инкапсуляция

	Изолирование данных

		class {
			private:
			...
			public:
			...
			protected: // то что наследуется
			...
		}

2. ### Полиморфизм

	Разные реализации в одинаковом синтаксисе

3. ### Наследование

	Данные можно передавать от классов-родителей к классам-детям

## Конструктор - деструктор

Конструктор вызывается при создании объекта класса, ему можно передавать аргументы для инициализации. Он всегда паблик, может быть перегружен.

Деструктор всегда один, всегда паблик. Пишется через **~C()**.

### Конструктор копирования

	C(C& obj);

### Конструктор перемещения

	C(C&& obj);

## Геттеры - сеттеры

	d = cmplx.real();
	d = get_real(cmplx); // функция от объекта
	d = cmp.get_real(x); // метод класса

## Правила

### ODR

One description rule

### RAII

Resource aquisition is initialization

1. Конструктор выделяет память
2. Деструктор освобождает
3. Взаимодействие с ресурсом происходит через взаимодействие с объектом

Защищает от утечек памяти

## Про поля

### Static поле

может изменяться сразу для **всех** объектов класса, например при вызове конструктора можно увеличивать static счетчик на 1

Обращение происходит через **::**

	my_class::a = 0;

## Public, private и protected

	Class C {
		public: // разрешен доступ вне класса
			int a;
			void fa();
		private: // доступно только в классе
			int b;
			void fb();
		protected: 
			...
	}

### Наследование

Наследуются все поля -- Public, private и protected. К Private доступ запрещен **всем**, в том числе дочерним классам, но если в родительском классе есть паблик геттер или сеттер, то можно пользоваться ими.

## Про файлы

.h и .hpp - одно и то же

Инклюд заголовочного файла работает как вставка куска кода.

Файл **class.cpp** может содержать большой класс (его определения). Хэдер может содержать прототипы всего что содержит класс без определений.

**#pragma once** -- директива, избавляющая от множественного определения при наследовании.

## Макросы

Выполняются препроцессором до компиляции. Простейший пример: **#define**.

	#ifndef H_GF
	#define H_GF
		Class GF {
			...
		}
	#endif // альтернатива pragma once

Примеры дефайнов:

	#define LENGTH 80
	#define WIDTH LENGTH + 10
	#define MIN(a,b) ((a>b) ? b : a)

	sqr = WIDTH*20; // тупая подстановка -> получится 280!
					// скобочки (LENGTH + 10) решают проблему

## lvalue / rvalue

lvalue -- это объект, на который нет ссылки, к нему нельзя обратиться.

### Иденцифицируемость (i)

### Перемещаемость (m)

## Перегрузка операторов

нельзя перегружать унарный %, тернарный оператор.

# Наследование

	Class1 : /* public/private/protected */ Class2

Если создать объект дочернего класса, то вызовется сначала конструктор родительского:

	A->B
	B obj b

	A()
	B()
	~B()
	~A()

protected ведет себя как private, но в отличии от private он будет доступен внутри наследника (но не извне, т. е. сделается в нем private).

Запрет на переопределение функции в дочерних классах:

	void f() final;

## Шаблоны

	template <typename T = int>

	// Функция сортировки
	vector<T> sort(vector<T>);

	vector<int> v1;
	sort<int> (...)

## Специализация типа

	template <typename T, typename U>
	struct S {
		void f() { cout << "1"};
	}

### Полная специализация

	template <>
	struct S<int, char> {
		void f() { cout << "2"};
	}

### Частичная

	template <typename T>
	struct S<T, T> {
		void f() { cout << "3"};
	}

Если будет пересечение, то при создании объекта выберется тот вариант, который ближе в коде. 

### Пример

	template <typename T, size N>
	struct array { ... };

	array<int, 5> a1; 
	array<int, 10> a2; // а1 и а2 это абсолютно разные типы!

Использование специализации с функцией вместо перегрузки позволяет обнаружать ошибки еще на этапе компиляции!

### Шаблонные параметры шаблона

	template < ... >
	class A {}

	template <typename T, template <typename> class A>
	class B {
		A<T> a;
		T t;
	}

### Наследование и шаблоны (CRTP)

	template <typename T>
	class Base {
	private:
		T* f();
	}

	class Derived: public Base <Derived>

### Проблема зависимых имен
 
 	template <typename T>
 	struct base {
 		template <int a, int b>
 		struct der {};
 	}
 
	template <>
	struct base<int> {
		int der = 0;
	}

	template <typename T>
	void f() {
		base<T>::der<1, 2> a; // ошибка
		typename base<T>::template der<1, 2> a; // успех
	}

# Метапрограммирование

	void Print() {}

	template<typename Head, typename... Tail> // вариативный шаблон
	void Print(const Head& head, const Tail&... tail) {
		cout << head << endl;
		Print(tail...); // рекурсивное инстанциирование шаблона
	}