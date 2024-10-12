/*
Из натурального числа удалить заданную цифру. Число и цифру вводить с клавиатуры.
Например, задано число 5683. Требуется удалить из него цифру 8. Получится число 563.

Решение оформить в виде функции delete_digit.  
Функция принимает в качестве аргумента целое число (number)  и удаляемую цифру (digit), а возвращает исходное число без указанной цифры

int delete_digit(int number, int digit)
{
	int result=0;
	//...
	return result;
}

Решение:
Задача усложняется тем, что заранее неизвестно количество разрядов числа. Поэтому исходное число проще начать проверять с конца с помощью оператора mod (нахождения остатка от деления). Делить надо на 10, чтобы получить последнюю цифру числа. Если последняя цифра не совпадает с цифрой, которую требуется удалить, то ее надо перенести в другое число, перед этим сдвинув его разряды. Легче реализовать, чтобы новое число формировалось наоборот: старшие разряды исходного будут младшими. После того, как заданная цифр будет удалена, число снова переворачивается.

*/

int delete_digit(int number, int digit)
{
        int result=0;
        //...
        return result;
}


int main()
{
	//...
	return 0;
}
