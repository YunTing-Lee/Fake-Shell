#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h> // gethostname
#include <stdio.h>

using namespace std ;

void printPrompt();
void readCommand( string & cmd, string & rmSpaceCmd) ;
void executeCommand( string cmd ) ;

int main( int argc, char** argv ) {

	string cmd, rmSpaceCmd = "";
	printPrompt();
	readCommand( cmd, rmSpaceCmd ) ;
	
	while( rmSpaceCmd != "exit" ) {	
		executeCommand( cmd );
		printPrompt();
		readCommand( cmd, rmSpaceCmd ) ;
	}// while
	
  return 0 ;
  
} // main()


void printPrompt(){
	char hostname[50] ;
	gethostname( hostname, sizeof(hostname)) ;
	cout << hostname << " : " << getenv("PWD") << endl << getenv("USERNAME") << " > " ;
} // printPromt()


void readCommand( string & cmd, string & rmSpaceCmd ){

	rmSpaceCmd = "" ;
	getline(cin, cmd ) ;
	int firstNotWhite = 0, lastNotWhite = 0;
	for( int i = 0 ; i < cmd.size() ; i++ ) {
		if( cmd[i] != ' ' && cmd [i] != '\t' ) {
			firstNotWhite = i ;  
			break ;
		}
	}
	
	for( int i = cmd.size()-1 ; i >= 0 ; i-- ) {
		if( cmd[i] != ' ' && cmd [i] != '\t' ) {
			lastNotWhite = i ;
			break ;
		}		
	}
	
	for( int i = firstNotWhite ; i <= lastNotWhite ; i++ )
		rmSpaceCmd = rmSpaceCmd + cmd[i] ;
	
} // readCommand

void executeCommand( string cmd ){
	FILE* fp = popen(cmd.c_str(), "r");
    if ( popen != NULL ) {
		while(!feof(fp)){
			char results[512] ;
			if (fgets(results, sizeof(results), fp) != NULL)
				cout << results ;
		}
	    pclose(fp);
		cout << endl ;
	} // if
    else{
        printf( "File pointer points to NULL.\n" );
    }	
} // executeCommand()

