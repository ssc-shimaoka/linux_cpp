#include <memory>
#include <iostream>
#include <ctime>

int main()
{
	time_t curr_time;
	curr_time = time(NULL);

	char *tm = ctime(&curr_time);
	std::cout << "Today is : " << tm << std::endl;
	
	return 0;
}