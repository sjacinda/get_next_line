# get_next_line


	Функция работает при чтении из файла (fd >= 3) и при чтении из стандартного ввода (fd == 0).
	Функция возвращает прочитанную до '\n' строку. Если произошла ошибка чтения или BUFFER_SIZE < 1 функция возвращает NULL.

	# ifndef BUFFER_SIZE	// таким образом в header file можно переопределить BUFFER_SIZE, если подаётся BUFFER_SIZE < 1
	#  define BUFFER_SIZE 1 // но в моей функции данный случай не обрабатывается — возвращется NULL.
	# elif BUFFER_SIZE < 1
	#  undef BUFFER_SIZE
	#  define BUFFER_SIZE 1
	# endif
	
	Для компиляции программы используется эта конструкция:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c && ./a.out
