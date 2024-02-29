#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	extern char **environ;
	int i = 0;
	while(environ[i] != NULL){
		//For printing all stuffs...
		printf("%s\n", environ[i]);


		// if(environ[i][0] == 'U' && environ[i][4] == '='){
		// 	printf("%s\n", environ[i]);
		// }
		// if(environ[i][0] == 'H' && environ[i][4] == '='){
		// 	printf("%s\n", environ[i]);
		// }
		
		i++;
	}
	return 0;
}

