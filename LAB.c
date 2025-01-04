#include <stdio.h> // puts, printf, scanf function
#include <string.h> // strlen, strcmp, strcpy function
#include <stdlib.h> // malloc function
#include <Windows.h> // Sleep, system function
#include <conio.h> // getch function
#include <ctype.h> // toupper, tolower, isalpha function

/* NOTE: Use windows dev c to use Windows.h lib



A Mystery and Enigma

Later the user will choose a game and a menu, which has a mystery theme, when the user has 
entered the game, there will be several clues given to the user to solve and complete. */



typedef struct{
	int day,month;//year always same.
} Date;

typedef struct{
	int hour,min;
} Time;

typedef struct{ //the data structure, consist of date, employeeId, and time
	Date date;
	char employeeId[20];
	Time time;
} Data;

//basic functions
void type(char str[]);
void clear();

//helper functions
int askInt(char str[]);
char* askStr(char str[], int max);
int ask(char str[][100], int n);
void askEnter();
void pict(int p);
void removeOpt(char A[][100], int size, int n);

//file read and write
int createNewFile();
int save(int progress, int checkpoint, char name[100], char culprit[100], int lose);
void load(int* progress, int* checkpoint, char** name, char** culprit, int* lose);
int loadData(Data* data);

//searching & sorting
void display(Data data[], int max);
void display2(Data data[], int max);
void display3(Data data[], int max, int num);
void swap(Data* a, Data* b);
void bubbleSortData(Data* data, int numData);


int main(){
	
	//MAIN PAGE
	
	int progress = 0,lose = 0,checkpoint=0;
	char *culprit=NULL,*name=NULL;
	Data data[126];
	
	int result = loadData(data);
    if(result == 1){
        printf("Error loading data.\n");
        return 1;
    }
	
	start:
	
	//load progress data inside file
	load(&progress, &checkpoint, &name, &culprit, &lose);
	
	//printf("name: %s",name);Sleep(99999);
	if(!name||name==NULL||progress==0){
		clear();
		name = askStr("\n\t _____                                                                     _____ \n\t( ___ )                                                                   ( ___ )\n\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n\t |   |     _      __  __           _                                    _  |   | \n\t |   |    / \\    |  \\/  |_   _ ___| |_ ___ _ __ _   _    __ _ _ __   __| | |   | \n\t |   |   / _ \\   | |\\/| | | | / __| __/ _ \\ '__| | | |  / _` | '_ \\ / _` | |   | \n\t |   |  / ___ \\  | |  | | |_| \\__ \\ ||  __/ |  | |_| | | (_| | | | | (_| | |   | \n\t |   | /_/___\\_\\ |_|_ |_|\\__, |___/\\__\\___|_|   \\__, |  \\__,_|_| |_|\\__,_| |   | \n\t |   | | ____|_ __ (_) __|___/__ ___   __ _     |___/                      |   | \n\t |   | |  _| | '_ \\| |/ _` | '_ ` _ \\ / _` |                               |   | \n\t |   | | |___| | | | | (_| | | | | | | (_| |                               |   | \n\t |   | |_____|_| |_|_|\\__, |_| |_| |_|\\__,_|                               |   | \n\t |   |                |___/                                                |   | \n\t |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n\t(_____)                                                                   (_____)\n\n\tWe highly recommend to fully display your console screen\n\n\tKindly enter your preferred name: ", 10);
		name[0] = toupper(name[0]);
		save(1, checkpoint, name, culprit, lose);
	}else{
		clear();
		printf("Progress: %d/5\n\t", progress);
		printf("Welcome back, detective %s!\n\t",name);
		Sleep(1000);
	}
	clear();
	
	
	//Checkpoint 0
	if(checkpoint==0){
		printf("It is just another normal day in the Detective %s's office.\n\tThat is until the phone rang and you heard a familiar voice calling for help.\n",name);
		askEnter();
		puts("It was Rosie, your former classmate in highschool.\n\tShe, now being the wife of a museum's manager, asked you for help for her own husband murder case.");
		askEnter();
		pict(0);
		puts("You: \"So could you please explain calmly what has happened?\"");
		askEnter();
		pict(1);
		puts("Rosie: \"I was waiting for Jeremy, my husband, to go home...\"");
		askEnter();
		pict(1);
		puts("Rosie: \"But instead of hearing the sound of the door bell, I receive a call telling me that my husband is dead.\"\n\t(starts to weep)");
		askEnter();
		puts("You then decided to stop questioning Rosie, seeing as she weeps upon remembering the accident that has happened.\n\tSo you decided to question the police instead.");
		askEnter();
		checkpoint=1;
		save(progress, 1, name, culprit, lose);
	}
	
	//Checkpoint 1
	if(checkpoint==1){
		puts("The police told you that the murder happened around 9 pm, two hours after the museum closed. The body was near the manager's office.\n\tThere were only around three suspects that were still at the museum at the time, the janitor, the tour guide and the night guard.");
		askEnter();
		puts("Clue: The museum closes at 19:00.");
		askEnter();
	
		//museum
		puts("\n\t%#*++++=-+#*++++++++***++**********************######################################################\n\t#*#%%*+-=+==-**=+====*+******************************################################################\n\t+*####%%#*======+***++++******************************************###********########################\n\t---=+*####%%#+==+===+**++*********************************************************#########****######\n\t*+------+*###*#%*=-++++*#++*************************************************************************#\n\t::-=+=--:::=*####%%#+=+++-+*+***********++*******************************************************+++*\n\t=-::::-=++=----=*###%%%#++++=++*******+====++*****************************************************++*\n\t*****-::::--++=-:--=*#%##%%*+=+=+****+++*****+===+**************************************++++*********\n\t@@#+===+*-::.::-++=----+*%#*#%#+=*+**+*++==----=++************************************++*++**********\n\t%#%%#**#++*#+=-::::-===---=+###%%%+=+***+++==-==+****************************************************\n\t%%%*==-=%####****+=::::-=+=----+********+++++++******************************************************\n\t%%%+-:-=#%%%@%%%*+==+*=::.::=+-:+*******++***********************************************************\n\t%%#=:::=#%%%%##%%##+*+=#**=-:::-+*******++*********************************************************++\n\t%%#=:::=#%%%%@@@%+-:=#%%%#%#++==+*******=+*****************************************************++++++\n\t###=:::=#####@%%#=::=**##*%%%**+:=****++=+++++++++++++*+****************************************++==+\n\t*#*-:::=##**#%#**-::=#%*+++*+-:+*+++++++=+++++++++++++++++++++++++++++++++++++*******************++++\n\t##*-:::-##**#@%**-::-#**+++*=::+++++++++=+++++++++++++++++++++++++++++++++++++++++++++++++***+**+++++\n\t##*-:::-##***%*++-::-#*=--==-::-========----=++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t##*-:::-==-=*%*==-::-###*==+-::===*+=++***+++-=++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t%#*-:::-==--*%*++-::-#*=-=*+-::==----==-----=++===----===++++++++++++++++++++++++++++++++++++==++++++\n\t#*+-:::-+=--*#+=+-::-==---==-::=+****+--:-=-=--=++----:::-==+==++++++===+++++++++++=-::---::-=+++=+++\n\t*#*-:::===--*#*++:::-=+++===-::-=--:--+****+----=-**--:::::------:::-===++===+++++=--::::::---==++===\n\t*#*-:::===--*##%*:::-++++##+-::=+=---------==+***+=-==---:::------:::::---===+******==---:-----------\n\t#*+::::=-=--*##%*:::-+=-=%%+-::+##*+*##+==-----==--=+***=---==+++**+++**++*##########+++=------------\n\t##+::::===--###%*:::-+=-=##+-:-+#%==#%%=+###+*#*=-::--::===+*########%#%%%%##****++=-*##*++=-----=#+=\n\t##+::::===--*+*#+:::-+=-=#%+-:-*%#=-#%#=+%%+=#%++##++*+--=****+**++++++++*+++++**+=+=====*#*+==*#####\n\t#*+-:::===-=+-+#+:::-+=--*#+-:-*##==#%#-=%#+=##++##-+*===++***+###**#%%#*%%%#*#%@@#=#*#*+=-===+*#%###\n\t#*=-:::=+===*=+#+:::=+==-*%+-:-*##==*%*-=#*=-**==#*-=+-=*#+%%%=*%%#-#%%#=*%%#=*%%%*=*=+*=**+-=++=%##*\n\t##=-:::==---+=+#+:::=+==-*%+-:-*##=-*%*-=#+=-*===++-=+-=**=#%#=+%%#-*%##=*###++#+**=*==+-+=+####*####\n\t##=-:::===-=+=+#=:::=+====%+-:-*##=-*#*-=#+=-*==-=*-==-=**=###=+#%#-*%##=*%%#+=+++*=*==+-+=+*++#+=**=\n\t##=-::-==---+=+%=:::====-=#+-:-*##=-*#*-=*+=-+===**:==:-**=###=+###-*###=*%+++==+++=*==+-+==*=-++-=+-\n\t##=:::-==-:-+-*#=:::======#+-:-*##==++*--++=-++==##-==-=**=###==###-*###=+%+=+===++=+==+-==+#==*+-**-\n\t##=-::-=*--=+=*#=-::=***++#+-:-*##+=++*==++=-+*==*#-==-=**=###==###-+###==++++====*=+==+-+==*==*+-+*-\n\t#*==---==---#+#*-----=*=-+#+---=#*==++#=-+++=*%==+*-=+==**=###=+###**###*****##*=-+=+=++-+==#==*+=**-\n\t:----::..--:----::-:..:--=:----:-+****+*******#****+*#*****++++***##+*##*#%###%##**+++=--==-+++++++++\n\t::-:::::::-:--------:------------+***+++++==+=+=============+**=+****#**+*******#*******+#****#***#**\n\t=----=------------------------======-============-----------=**--=*===++++**####%###**###**+++*####**\n\t+****#**++**+++===++=-=-----------------=======++++++++++***++++++++*********######%%##*****#%%@@%%%*\n\t==+**++===++++*+++*****##*##########%######*#####%%%%%%%%%%%%%%###%%%%%%##########%%%%%##%%#%%%%%%%%%\n\t*##*#%%%%%####%%%%%%%%%%%####%%####%%%%%%%%%%%%%%%%%%%%%%#####**#*#**#%%%@@@%%@@%@@@%@%#############%\n\t+==+++**##%%%%%%##%%%%%%%#%%%%%%%%#%%%%%%%%%%###********##%%*#%@@@%%*%%%%%%%#@@@@%%%%#####%%%%%%%%%%%\n\t###%%%###%%%%%%%%%%%%%%%%%%%%%%%#####*****#####%%%%%@@@@@%%*#%%%%%%%%@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\t");
		askEnter();
		
		//detective
		pict(0);
		puts("You: \"After the museum had closed?? How can we determine the suspects then..\"");
		askEnter();
	
		puts("You need to find out around what time the murder happened to pinpoint who the suspect is.");
		checkpoint=2;
		save(progress, 2, name, culprit, lose);
	}
	
	//Checkpoint 2
	if(checkpoint==2){
		char actionz[5][100] = {"What would you like to do now?","Check your phone","Check the clock-out logs","Search clock-out logs","Check your bag"};
		int pickedActionz[4], sorted=0;
		for(int i=4; i>0; i--){ //until no option available
			int action = ask(actionz,i);
			pickedActionz[4-i] = action;
			switch(actionz[action][11]){ //checking the 12th character of string (no same case; making it always sync)
				case 'p': //Check your 'p'hone
					puts("You checked your phone. Your battery percentage is 69%, it's currently 10:00, 31st of February 202H, you received 5 messages from your secretary.");
					break;
				case 'l': //Check the c'l'ock-out logs
					puts("You open the clock-out logs.");
					//show table
					display(data,result);
					break;
				case 'k': //Search cloc'k'-out logs
					puts("You wanted to search the clock-out logs. Because of the dated technology in the museum, you can only insert the day of the date you want to search.");
					askEnter();
					int num = askInt("\n\tInsert day of date: ");
					if(sorted && num>=26 && num<=30){
						//Note: cmn bisa kalo udh sorting, kl blm sorting/ tanggalnya selain 26,27,28,29,30 outputnya gini:
						//klo udh sort dan masikun angka 26/27/28/29
						puts("\n\tYou entered the day of the date you wanted.");
						askEnter();
						//[Nunjukin hasil data tanggal 26/27/28/29 yang udah di-sort]
						display3(data,result,num);
						askEnter();
						if(num==26||num==27||num==29){
							//Lanjutan kl 26/27/29
							puts("You saw the only person who was still there after the museum closed. It was a tour guide/a night guard/a janitor with the ID, \"tourGuide08\"/ \"nightGuard17\"/ \"janitor02\". Since they were the only one there, it has to be them.");
							askEnter();
							//Langsung lanjut ke **Lanjutan Kl jawab slh satu dr 3 org td**
							checkpoint=4;lose=1;
							save(progress, checkpoint, name, culprit, 1);
							continue;
							break;
						}else if(num==28){
							//kl udh di-sort dan dimasukin angka 28
							printf("You entered the day of the date you wanted.\n\t");
							askEnter();
							//[Nunjukin hasil data tanggal 26/27/28/29 yang udah di-sort]
							display(data,result);
							askEnter();
							//Lanjutan kl 28
							pict(0);
							puts("You: \"It was...himself???\"\n\n\tAfter that you decided to dismiss the case since it's just an act of suicide. What a horrid end for him..");
							//lanjut ke credits
							checkpoint=5;
							save(progress, 5, name, culprit, lose);
							continue;
							break;
						}else if(num==30){
							//kl udh di-sort dan dimasukin angka 30
							puts("You entered the day of the date you wanted.");
							//[Nunjukin hasil data tanggal 26/27/28/29 yang udah di-sort]
							askEnter();
							//Lanjutan kl 30
							//ke actions
							checkpoint=3;
							save(progress, 3, name, culprit, lose);
							continue;
							break;
						}
					}else{
						//cmn bisa kalo udh sorting, kl blm sorting/ tanggalnya selain 26,27,28,29,30 outputnya gini:
						puts("You entered the day of the date you wanted. You wait and you wait...");
						if(num>25&&num<31)
						display3(data,result,num);
						//Lanjutan kl blm sorting/ tanggalnya selain 26,27,28,29,30
						puts("\n\tSuddenly, the computer started shaking then BOOM!\n\tYou died.\n\tMaybe the computer was too dated..");
						//meme
						puts("\n\t::::::::::::=+++++++++++++=-=+++++++++++-::::::::::\n\t::::::::::+++++++++++++++++**+++++++++++++:::::::::\n\t::::::::-+++++++***++++***++*+++++++++++++=::::::::\n\t:::::::-++++++*+++++++++++++*#**+++++++****=-::::::\n\t::::::-+++++++++++++++***+++**#*++++++********+-:::\n\t:::::-++++++++++++*++**++***++*******#*+++++*#**+-:\n\t:::+++*+++++++**++*++-##@@%-...-*++++==#+@@%-.:*+*-\n\t:-+++*++++++**+++=...#@%%=%%:....--..:#@%@+%%....:=\n\t:*+++++++++++++++=:..#@@@@@#.....-...:#@@@@@+...:=-\n\t*++++++++++++++++**++++++=-:=*++**+=++**%##*+++*+-:\n\t+++++++++++++++++++++*########*+++++++++++++++*::::\n\t++++++++++++++++++++++++++***++++++****+++**-::::::\n\t+++++++++++++++++++++++*++++++++++++++++++++++:::::\n\t++++++++++++++++++++++++++++++++++++++++++++++*::::\n\t+++++++++++++++++++++++++++++++++++++++++++++++=:::\n\t++++++++++++++***++***#*++**++++++++++++++++*+**=::\n\t+++++++++++++*++*******++++++**************+++++-::\n\t+++++++++++++*+++++++++++*******#########*****=::::\n\t+++++++++++*++++++++++**##*++++++++++++++++++*-::::\n\t=*+++++++++++*+++++++++++++++++++++++*****--:::::::\n\t###****++++++++++++++++++++++++++++++++=:::::::::::\n\t#######*++*******++++++++++++++++*+=:::::::::::::::\n\t#############***++++++++++++++*####-:::::::::::::::\n\t#####################################*-::::::::::::");
						askEnter();
						//lanjut ke credits
						checkpoint=5;
						save(progress, 5, name, culprit, 0);
						continue;
						break;
					}
					break;
				case 'b': //Check your 'b'ag
					puts("You look through your bag and found a black square device. You then remembered that on of the hacker on your team gave it to you. He said it was to sort files. You decided to took it out. Maybe it'll be useful for something..");
					if(i<=2 && (pickedActionz[0]==2 && pickedActionz[1]==1) || (pickedActionz[1]==2 && pickedActionz[2]==1)){
						askEnter();
						puts("You decided to use the device to sort the Check the clock-out logs to organize it.");
						//sort data
						bubbleSortData(data,result);
						sorted=1;
						// Nunjukkin clock-out logs yang udh tersusun
						display2(data,result);
					}
			}
			askEnter();
			removeOpt(actionz,i,action);
		}
		if(checkpoint==2){
			checkpoint=3;
			save(progress, 3, name, culprit, lose);
		}
	}
	
	//Checkpoint 3
	if(checkpoint==3 && !lose){
		char actions[6][100] = {"What would you like to do now?","Question the janitor","Question the tour guide","Question the nightguard","Talk with Rosie","Explore on your own"};
		for(int j=5; j>0; j--){ //until no option available
			puts("From the data shown, there are only 3 suspects in this case, the janitor, the tour guide, and the nightguard.\n");
			askEnter();
			int action = ask(actions,j);
			switch(actions[action][13]){//checking the 14th character of string (no same case; making it always sync)
				case 'j': //Question the 'j'anitor
					pict(3);
					puts("Janitor: \"The name's Jimmy and I didn't do nothin'. That night, I was just moping, wiping all around the museum...\"");
					askEnter();
					puts("You find it interesting how Jimmy heard two people arguing in the manager's office. Maybe it's related to the murderer's motive.");
					break;
				case 't': //Question the 't'our guide
					pict(2);
					puts("Tour Guide: \"Hi, I'm Frida. I would try to do anything in my best efforts to help this investigation. Afterall, Mr. Mort is very dear to me.\"");
					pict(2);
					puts("Tour Guide: \"Yes, I do go to his office. We usually discuss all sorts of things there, formally and informally.\n\tHonestly, he's such a nice person, always welcoming me once I enter and never forgets to give me gifts after. It's such a tragedy seeing him go early\"");
					askEnter();
					puts("You could tell she was serious about trying to help the best she could.\n\tEverytime you ask her about something, she answers in such detail it isn't relevant anymore.\n\tIt is fascinating how she's a person who can easily enter and exit the manager's office.");
					break;
				case 'n': //Question the 'n'ightguard
					pict(4);
					puts("Night Guard: \"My name is Johnny. At the night of the murder, I was strolling around making sure that there aren't any intruders intruding the museum with my flashlight\"");
					askEnter();
					puts("You are a bit surprised at how straight-forward his answer is.\n\tEven so, that alibi isn't that strong to rule him out as a suspect.");
					break;
				case 'i': //Talk with Ros'i'e
					puts("You decided to wait until she calmed out. The sudden news must've shocked her.");
					askEnter();
					pict(1);
					puts("Rosie: \"I can't believe he's gone.\" (sniff)\n\tI haven't been spending time with him because of the busy work.\n\tHe was always comes home late, around 11 pm...\"");
					pict(1);
					askEnter();
					puts("Rosie: \"I guess I should probably talk with Frida later. Jeremy has been talking a lot about her lately.\n\tI heard she's really sweet. Jeremy tells me everything. To think she's one of the suspects in my husband's murder case. Ironic isn't it?\"");
					askEnter();
					puts("You find it odd how Frida seems to be related to a lot of this in this case. But the puzzle does fit. \n\tOf course, everything is still uncertain.");
					break;
				case 'u': {//Explore on yo'u'r own
					puts("You explored the crime scene, carefully examining every detail that could be overlooked.");
					askEnter();
					char objects[9][100] = {"What do you want to check?","Office table","Bookshelf","Bulletin board","Clock","Calendar","Chair","Door","Carpet"};
					for(int k = 8; k>0 ; k--){
						//explore:
						int object = ask(objects,k);
						switch(objects[object][3]){ //checking the 4th character of string (least same case; making it always sync)
							case 'i': {//Off'i'ce table or Cha'i'r
								if(objects[object][0]=='O'){//Office table
									char table[3][100] = {"There are nothing but a perfectly organized pile of documents\n\n\tKeep looking?","Yes","No"};
									switch(ask(table,2)){
										case 1:
											puts("You searched, searched and searched...");
											askEnter();
											puts("Then you found some things that are perfectly organized on the office table, as if someone purposely organized it. Looking a tad bit reddish-brown color.");
											askEnter();
											puts("A strange note was found. In it, it reads:\n\tA = 30 -> 46");
											break;
										case 2:
											continue;
									}
								}else{//Chair
									puts("You sat on the chai-\n\t\"SQUICK\"");
									askEnter();
									puts("That chair definitely needs to be replaced.");
								}
								break;
							}
							case 'k': {//Boo'k'shelf
								char books[3][100] = {"It's full of big thick history books.\n\n\tRead it?","Yes","No"};
								switch(ask(books,2)){
									case 1:
										printf("It opens to a marked page.\n\tIt says, \"Roots' set the record for a Latin American Piece of Art. She's truly golden\"\n\n\t-kL@H0\n");
										break;
									case 2:
										continue;
								}
								break;
							}
							case 'l': //Bul'l'etin board
								puts("You looked and examined the bulletin board, it was arranged to show everything on each exhibit...");
								askEnter();
								puts("There's the Egypt exhibit, stone ages, 1980s, 1800s, a piece of colorful paper, the golden ages. Wait, a piece of colorful paper????");
								askEnter();
								puts("It's a colorful striped wrapping paper, perfectly folded into a heart. It also has flamingos on it.");
								break;
							case 'c': //Clo'c'k
								puts("You stare at the clock, strange...");
								askEnter();
								puts("It's lunch time already?! No wonder you're feeling rather hungry.");
								break;
							case 'e': {//Cal'e'ndar
								char skim[3][100] = {"You skimmed the calendar.\n\n\tSkimmed more?","Yes","No"};
								switch(ask(skim,2)){
									case 1:
										puts("Right, Today's the 31st of February. Nothing's wrong about it.");
										break;
									case 2:
										continue;
								}
								break;
							}
							case 'r': //Doo'r'
								puts("It's a wooden door. A door made of wood.");
								break;
							case 'p': {//Car'p'et
								char carpet[3][100] = {"You checked the carpet.\n\n\tIt's dusty.\n\n\tKeep looking?","Yes","No"};
								switch(ask(carpet,2)){
									case 1:
										puts("Still very dusty.");
										break;
									case 2:
										continue;
								}
								break;
							}
						}
						askEnter();
						removeOpt(objects,k,object);
					}
					puts("You analyze those three odd misplaced things, only to conclude that those are clues.\n\tYou then nodded, thinking Jeremy carefully placed it there just before he died.");
					askEnter();
					continue;
					break;
				}
			}
			askEnter();
			removeOpt(actions,j,action);
		}
		checkpoint=4;
		save(progress, 4, name, culprit, lose);
	}
	
	//Checkpoint 4
	if(checkpoint==4||lose){
		while(1){
			if(!culprit||progress==1){
				culprit = askStr("After cracking the clue, you realized there's only one person capable enough to do this crime.\n\n\tIt's time to announce the culprit.\n\n\tThe culprit is ",10);
				culprit[0] = toupper(culprit[0]);
				save(2, checkpoint, name, culprit, lose);
			}
			clear();
			if(strcmp(culprit,"Janitor")==0||strcmp(culprit,"Tour guide")==0||strcmp(culprit,"Night guard")||strcmp(culprit,"Tourguide")==0||strcmp(culprit,"Nightguard")==0){
				if(lose){
					printf("You picked %s as the culprit. Soon enough a court meeting was organized to sentence him. They were sentenced for a full life in prison.\n",culprit);
					askEnter();
				}
				//Lanjutan Kl jawab slh satu dr 3 org td
				printf("Detective %s, you did it again, you solved the murder case!!\n\n\tOr did you?\n",name);
				//meme
				Sleep(1000);
				puts("\n\t             ......::--------::.....              \n\t          ....:--------------------:......        \n\t        ...:-----:::..........:::------....       \n\t      ...-----:....................:-----:.       \n\t    ...==--::........................::---=..     \n\t  ...:----:::::::::::::::::::::::::::::::----..   \n\t ...----::::::::::::::::::::::::::::::::::----... \n\t...----::::::--:::::::::::::::::::--:::::::----...\n\t..----:::--=-=*#*=-::::::::::::-+##+-=-=-:::----..\n\t.:=----==-:::-=+*#*=:::::::::-*##*==::::-==----=:.\n\t.----=-........:=+##+:::::::=##*+-....:...:=-----.\n\t.=----...+%%#:..:-=##=--::--##+--:..=%%%-..:=---=:\n\t:=----...-##+...:--=#+--::-=#+---:..:*#+:..:----=:\n\t:------........:=--:---::::---:--=:.......:=-----:\n\t:=-----+-:..:-=-:--:::::::::::::---=-:::-=+=----=:\n\t.=--=++=-::=*=----------------------=#+-:-=+*+--=:\n\t.=++=----:-+*###%%###********##%%%%%##+-::---=++=.\n\t:++=-------++-:::::::-----------::::-=+-------=++:\n\t=+===-----=**+=-:::............:::-=***=-----===+=\n\t-*========+*++**********************++*+========*=\n\t.=*+====++=-=++++++++++++++++++++++++=-=+=====+*=.\n\t...-+**+=-:---=++++++++++++++++++++------=***+=:..\n\t    ...==----:---=++++++++++++++=--::-----=..     \n\t       .:-------------==++==-------------:.       \n\t        ...----------------------------...        \n\t          ....:--------------------:....          \n\t              ....:::--------:::....              \n\n");
				Sleep(1000);
				lose = 1;
				save(3, checkpoint, name, culprit, 1);
				break;
			}else if(strcmp(culprit,"Rosie")==0){
				puts("You thought something was fishy all right. You knew that someone organized those things to tell you something. Though those things could be placed by Jeremey, it could also be placed by the murderer...");
				askEnter();
				puts("You tried to find something odd-placed than the other three. And to your surprise, you found a wilted rose, slowly dying.");
				askEnter();
				puts("It was Rosie, his own wife. But why her? Doesn't she love him? She does, but does he? He goes home late, stating that he has a lot of work. But what busy work does a museum manager do that makes him have to stay late in his office? It didn't work at all. It was simply an affair with one of his employees, Frida.");
				askEnter();
				puts("She accidently figured it out when she wanted to surprise him at work. Him looking at her with the same magical stare she used to know.");
				askEnter();
				puts("You questioned Rosie, alone. She immediately confessed to the murder, feeling guilty of the murder. She was then sentenced to 5 years in jail.\n\n\tThe End");
				askEnter();
				break;
			}else{
				clear();
				puts("Not a valid option.");
				Sleep(820);
				char try[3][100]= {"What would you want to do?","Restart","Try again"};
				if(ask(try,2)==1){goto start;}
			}
		}
	}
	
	
	
	//EXIT + CREDIT PAGE
	clear();
	pict(0);
	type("\n\n\n\n\t\t\t\t\t\tHope u enjoy :>\n\n\n\tCredits (Kesatria Gender)\n\n\n\n\n\n\t\t\t\tThank you for playing our game! <3");
	if(lose){
		Sleep(2000);
		clear();
		char last[3][100] = {"\n\tPlay Again?\n","Yes","No"};
		if(ask(last,2) == 1){
			char lastt[6][100] = {"\n\tStart From?\n","Begining","Checkpoint 1","Checkpoint 2","Checkpoint 3","Checkpoint 4"};
			int num = ask(last,checkpoint)-1;
			progress = (num==0)?0:(num<5)?1:progress;
			save(progress, num, name, culprit, 0);
			goto start;
		}
	}
	return 0;
}
void type(char str[]){ //print char one by one with delay to have type animation
	for(int i = 0; i < strlen(str); i++){
		printf("%c",str[i]);
		Sleep(1);
	}
}

void clear(){ //clear console screen
	system("cls");printf("\n\n\n\t");
}

int askInt(char str[]){ //ask for an integer with error handling
	char input[100];
	int num;
	while(1){
		printf("\n\t%s",str);scanf("%[^\n]",input);getchar();
		//check validity for numbers
		clear();
		if(sscanf(input,"%d",&num)!=1){ //error handling
			printf("\n\tInvalid input. Please enter an integer.\n");
	    }else{
	        return num;
	    }
	}
}

char* askStr(char str[], int max){ //ask user to input string
	char* str2 = (char*)malloc(max*sizeof(char));
	int j = 1;
	while(j){
		printf("\n\t%s",str);scanf("%[^\n]",str2);getchar();
		//check validity (letters only)
		for(int i = 0; i < strlen(str2); i++){
			if(!isalpha(str2[i])){
				clear();
				printf("\n\tNumbers and symbols are not allowed!(%c)",str2[i]);
				break;
			}else if(i==strlen(str2)-1){
				j = 0;
			}
		}
	}
	printf("\n\n\t");
	return str2;
}

int ask(char str[][100], int n){ //ask user to choose from provided options
	int a = 1, i;
	while(1){
		printf("\n\t%s\n", str[0]);
		for(i = 1; i <= n; i++){
			printf("\t%d. %s%s\n", i, str[i], (i==a)?" <":"");
		}
		printf("\n\tPress %c or W to go up\n\tPress %c or S to go down\n\tPress Enter or Spacebar to select\n\n\n\t",24,25);
		switch(getch()){
			case 'w': case 'W': case 72: if(a>1){a--;} break;
			case 's': case 'S': case 80: if(a<n){a++;} break;
			case ' ': case '\r': clear(); return a;
		}
		clear();
	}
}

void askEnter(){ //ask user to press ENTER
	printf("\n\t[Press ENTER to continue]\n\t");
	while(1){if(getch()=='\r'){clear();break;}}
}

void pict(int p){ //show picture (pixel art in ascii char)
	char person[5][5270] = {
	//you (detective)
	"..........................-%@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@%%%%%%%%%%%%=...........................\n\t..........................*@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@%%%%%%%%%%%*...........................\n\t..........................%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%#:..........................\n\t.........................-%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%-..........................\n\t.......................:=%%%@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@%%%@@@%%@@%%%%-..........................\n\t..........:--+*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@%%%%%%%%%%%+::::::::..................\n\t....:+#%%%%%%%%%%%%%%%%%%%##%%%%%%%%%%%###%%%%@@@%%@@@%%%*****#%%%@@@%%%%%%%%%%%%%%%%%###*=.........\n\t....+#####%%%%%%%%%%%%%%%%##%%%%%%#####%%%%#****#***+++*##%#+++*#######%%%#%%%%%%%%%%%%%#%###+......\n\t........::::-=+*#%%@@%%%%%#########**#%%######*+++=========#%#++****#*#*=+++#@@@@%%%%%%%%%%##*-.....\n\t.........................:*###******#%#****++++++++====----=+#%*****++====+**@@@@@%%%%%%%%%#*-......\n\t..........................*##***+**##*++++***#####**++===-----*%***+=------*+%@@%%%%%%%%%#+:........\n\t..........................=*####**##*==++**###**#%#****+==-----##++=---++=--+#%%%%@%%#*=............\n\t..........................:+++**#*#*--==+*###**+*##*+=+==-------%+------*+=-+%@%%-..................\n\t............................+****#*+--==++*###****+====------::-#*-----+++==*@@%%+..................\n\t............................+***##*=--====+******+++=====----::-**----**=-==%%%##+:.................\n\t...........................:+**###*+---====+++++++++=====----::-#*---==---=###***+:.................\n\t............................=***###*-----===++++++++===----:::--%+-------+%#*****+:.................\n\t............................:+**##*#+-----==++++++++==---------##=-----=%%#+++++++:.................\n\t.............................-=*#-*%%+-----==++++++===--------*%+--===*@@%+++==+=+:.................\n\t..............................-**+*+%%*======++++====--------#%+--===+%@@*=======+:.................\n\t...............................+##*==*%%+===========-------*%#---====#%@%+======-=:.................\n\t...............................=#####*+#%%#+=====-------+#@*=----=-=*%@%*==---==-=:.................\n\t...............................:**##****+=#%@@@%#***%@@%%#------=-=+%@@#+=----==-=--:...............\n\t................................=******++=====+++*#%%@%#=------=--=%@@#+==-------=---:..............\n\t................................:*+####***++++++=----@%=*----==--+%%@%*+=--------=------............\n\t.................................:+++***++==-----==--*@#+=-==---*%@@@*+==--------=-=+**===-:........\n\t.................................-=###***++===-------=%@+*===-=%%%@@#*+=---------=-*#+=+****+=:.....\n\t................................:-+*##**++===--------=#%#*===#%%%@@%*+=--------=-=-*#%#+=++++==-:...\n\t................................-++*##***+====---===+++%%+##%%%@@@%*+=--------==-==***#%%*+===-=---:\n\t................................=*+==+***++++++++++++++#@*++*@@@@%*+==----=========***++*#%%#*=-----\n\t................................+*+=**%%%%%%%@@@@#++*##*@%++=+@@@#*+=----===+++===+#*+=+**##%%%+----\n\t...............................:+*++#*##%%@%@%@@%@@@@@*****=----=+==---==+++++===-+*+++*******#%*---\n\t...............................-+*=**++*#@%%@%@@@@@%+*****=--:::::---==++++++==---+******+++===+*#+=\n\t...............................=*+=+=+++#%@%@%%@%@%+**++++=---:::::::-=+++++==---=*##*++=====++++*+=\n\t...............................+*==++++***###%%@@@@**++++++==---:::::-::-++=-----=*++====++++++===++\n\t..............................:**-=+++******##%@@@@#++=++++++++==-::::::::-------======++**++++====+\n\t..............................=*+-+++********##@@@%++========-======----:::::----====++**++++++====+\n\t(picture of you)",
	//Rosie (wife)
	"------------=--=*******+-====-====**+++++++++++++++++++++++*###*************************\n\t------------=--=*******+-====-====**++++++++**#%%@%%#++++++*###*************************\n\t------------=--=*******+-====-====**++++++#%@@%%%@@@@@@#+++*##*****########*************\n\t------------=--=*******+-====-====**++++*%%%%#*###%@@@@@@*+*##*******###################\n\t------------=--=*******+-====-====**++++%@%+=====++*#%@@@@#*##**************************\n\t------------=--=*******+-====-====**+++#%%==---===++**#@@@@%##**************************\n\t------------=--=*******+-====-====**+++%%+==----=+#%####%@@@%#**************************\n\t------------=--=*******+-====-===+**++*%%++**+==+**##%**#@@%%%**************************\n\t------------=--=*******+-====-===+**++*@@#=+**+=+**++++**#%##@#*************************\n\t------------=--=*******+-====-===+**++*@@%+**+==+*+===+*#####@#*************************\n\t------------=--=*******+-====-=+=+**++*@@%==---==**+==+**##*@@#*************************\n\t------------=--=*******+-====-++=+**++*@@%+=---==++++++**###@@#*************************\n\t------------=--=*******+-====-++++**++*#@@%+===+*####++**#@@@@#*************************\n\t------------=--=*******+-====-++++**+++*#@@#+====+++++**#@@@@%#*************************\n\t------------=--=*******+-=+==-++++**++++*%@@@*==---=+*##%@@@@%#*************************\n\t------------=--=*******+-=+==-++++**+++*#%%%@@%+++++**##%@@@@@#*************************\n\t------------=--=*******+-=+==-++++***%%%@@@@%@@*====++##@@@@@@%#************************\n\t------------=--=*******+-=+==-++++*+=+=+%@@@%@@#=====+*#@@@@@@@%#***********************\n\t------------=--=*******+-=+==-++=---==++=+%%%##+==++++*#%@@@@%###***********************\n\t------------=--=*******+-=+==-------==+++=+****++++*+++%%%%##***##**********************\n\t------------=--=*******+-=+==------===+=+++*+=+******=*##%%%**++++**********************\n\t------------=--=*******+====----=--+=-=+=++*+==++***#+**##*#**+=++++#*******************\n\t------------=--=******#+-==-----+=-+=--++=+++*+++********###++==++=+********************\n\t========----=--=*******+--------+=-==---++==+=**********###*+===++=+********************\n\t========----=--=*******+-*=----=++-==---=+===+=+***********++===*+=+*#**#%%#***%%#******\n\t========----=--=*****##+====--==++-==----=+====+=*********+====+*+=**##*****************\n\t========----=--=****###+-=-=====++-==----=++====+==*#****++===+*+++**##******###%%#*****\n\t========----=--=****+#%+=--=====++-===----=++====++==***++====+*+++*###*****************\n\t-=======----=--=**##+*#=--====+=++-===-----=++==++++===+=====++*++**###*****************\n\t------------=--=#%%%+**--=====++++-===-----=======++++==+====+++++*####*****************\n\t-----------=##+=##%%+*=--====++*+=--==-------====+++++=======++++*#####******####*******\n\t------------=-==##%%+=---===++**+--===-------====+++++========++*######*#*###*****##***#\n\t--------=+-----=**##+=--===++*##+--===-------===+=++*+========+**##########*******######\n\t--------==-----=**##=---==++**#+=--===-----=+==++==+*=-===+==++**##########*#*****#*####\n\t--------==-----=**#*---===+**#+=---==-----=+==+==-=++=-=+++==++*#############*##**#**###\n\t--------==-----=***=--===+**-+=----=+-----++====-=++=-=+++====**%########%##########*###\n\t--------==--=--=***=-===+*#=-==----=+----=++==--=+=---+*+====+*#%######################%\n\t--------==-----=**+=-==+*#=--==----=+---==*+=--==--=-=*++===+**%%#########%############%\n\t--------==-----=**==-==+**=---=-----+=-===*=--=----==*+====++*%%%######################%\n\t--------==-:---=**+=-==+**=---==----+=-=+=+----===-=*+====+**#%%%##########%#####%#####%\n\t--------==-----=**+=--=++*+----=-=--==-==-+--++=--=+===++*##%%%%#################%%###%%\n\t--------==-:---=***=--==+*#----=-=---====-==+====++*###****#%%%####%%%%%%%%%######%%%%%%\n\t--------==-:=--=**#=--==+**=--=--------------===-=*=+*******#%%##*##@@@@%%%%%%%%%@%%%%%%\n\t--------==-:=--=**#*=--=+**+-===--=---=--==--=-=+=+-=***++*+*%%##**#@@@@@@@@@@@%%%%%%%%%\n\t--------==-:---=**##=--==+*+-+----=-=-=--=--==-+=+=-=*+**++*=*%##**#@@@@@@@@@@@@@@@@%%%%\n\t--------==-:=--=**##+--==+****---==:===--+--==:+===--*+*+*++::+%*+-=*+++%+#*#*#+#@***%@@\n\t--------==-:---=**###=--==+*#*---=--==-:==--==:+=+---*+*=*++*=#%#***%%%##%@@@@@@@@@@@@@@\n\t--------==-:---=***##*---=+**#---=--==-:+=--==:=++=-=+**=+*=++*%#***%@%#@@@@@@@%@@@@@@@@\n\t(Picture of Rosie)",
	//Frida (tour guide)
	"##*=-----==**===--+%+===-+=--==+#+==+##--=++===+***+++**+++=--------==+++-:=\n\t##*------==**+==--=+++++++=--==+#+==+#*--=++++*******+***+===-------===+=-:=\n\t##*=-----==*#+==------------===+#+==+#*--++===+***###*****+=--------=====::+\n\t##*=-----==*#+=================*#+==+%*--+++++**######*##**+++=-----==++=:-+\n\t##*=-----==*#+=================*#*++*%#*###**+++##+*#**#%#%#+=---=+++===-:-*\n\t##*=----===*#+=================*%%%%%@@@@@%##%%#**+*%++#####+--=+*****++=:-*\n\t###=----===##+=====+*****+====+%@%%@@#@@@@@%#%%%%#=+#=========+*****##*+---#\n\t###=---====##+======+===++===+@@%%%%##%@@%##%%@@@@%#%####*++++++++++++++--=#\n\t###=======+##+======+==+=+==+@@%%%*==-=+#%#%%@@@@@@@%*++++++####**+++=++--=#\n\t###=======+##+=====++==+=+=+%@@@%+=------=#%%@@@@@@@@#++++++#%%%%#++====--+#\n\t###=======+##+=====++====+=+@@@%+=------:--+*%@@@@@@@@*+++==+*%%#+=+++==--+#\n\t###=======+#%+=====++++++++#@@@#+=------::---+%#@@@@@@@=======++===+++*+--*#\n\t###=======+#%+=======++++++%@@@#**+==-=+**=---=#*#@@@#%*======++=====++=--**\n\t%##+======+#%+=========++++@@@@*==+*+--==*%%#+=--+#@#=*%+++++++++++++++=--#*\n\t%##+======+#%#***********+#@@@@@#@%**-:-=++=--::--+#*==%======+++++++++=-=#*\n\t%##+======+#%%%%%%%%%%%%%%@@@@#*++==+:::::-::::---++=-**=====------------=%*\n\t%%#+========+++++++++++++**@@@#+---==::----:::---=+=-=@%%%%%%%%%%%%%%%%##%%+\n\t%%#+==+#%%%%%%%%%%%%%%%%%%%@@@@*=-=*#***=-==-----=++#%@++++++++++++++++***+=\n\t%%#+==+##%%%%%%%%%%%%@@@@@@@@@@%*++**+=-:--==----=%@@%%============---------\n\t%%%+=+*##%%*======+++++++++*%@%@#**%%##**+===---=#@@@@#********+++++++====--\n\t%%%+=+*%#%%+======++++++++++*#@@@#*+##**=----==++@@@@@###################*=-\n\t%%%+=+*%%%%+=====**++=++*++***@@@@%*+=------=+*+=@@@@###*=============*#**=-\n\t%%%+=+*%%%%+=++**%*++++*#****#%#*%@##*++==+**++==##+*###*===------==--*#**=-\n\t%%%+++*%%%%*+***#%%####%%####*+**%%#@%%%##*++===-=-:=###*=======-===-=###*==\n\t%%%+++*%%%%*+***#%%%###%%%%###%#*%**@%%##*++===--....+##*===========-=###*==\n\t%%%+++*%%%%**####%%%%%%%%%%%%#**@*++#%##**++==-.....:=@%*=+=+=======-=###+-=\n\t%%%*++*%%%%#***********+=====+@@*++=-###**++-.......-%%@::-=+=======-+###+-=\n\t%%%*++*%%%%%%%%%%%%%#-------#@@%--==-:***+:::::::.:*%%%%-....-+*+++++*###+==\n\t%%%*++*%%%%%%%%%%%%+::-:--=@@@@#:-----:=:::::::..+@%%%%%-.......:=+++****===\n\t%%%*++*#%%%%%%%%%%+-:::::+@@@@@#:::::===:......-%%%%%%%%:.:........-####*=-=\n\t@@%*+++***********---:::=@@@@@@*::+*-:::=-...:#@@@%@@@@@:::..........=++=--=\n\t@@%*++++++++*****-::=:::%@@@@@@@@@@@@@@@@%%:+@@@@@@@@@@@:::::.:......:===--=\n\t@@%*+++++++++***+:-:-::+@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@:::::::::::...:==---\n\t@@%*************+:-::-:*@@@@@@@@@@@@@@@@@@@@%+*%@@@@@@@@:::::..::......==---\n\t@@%%%%%%%%@@@@@*=:--:--*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:::.::::......:****\n\t@@@@@@@@@@@@@@*-=::-::-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-::::::.:::::..*###\n\t@%@%##%%%%%%%#--=::--::#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::::.::::::::.+###\n\t@@@%##%%%%%%#---=:::--+@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@#-::::::::::::..+@@@\n\t@@@%##%%%%%%=-----::--=@@@@@@@@@@@@@@@@@@@@@@@@@@@@%--*@*:-::::::::.....-*%%\n\t@@@%%%%%%%%=---==-:::-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%*@@%=-:::::::::....:***\n\t@@@%%%%%%%+-----==:---+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-::::::::::....+**\n\t(Picture of tour guide)",
	//(janitor)
	";;;;;;;;;;;;;;;;;;;::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;:::::::::::::::::;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;::::::::::::;;;;;;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;::::::::;;;;;;;;;;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;::::;;;;;;;;;;;;;;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;::;;;;;;;;;;;;;;;;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:::::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:;xxx+;::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;++;;;;;;;;;;;;;;;++++++++++++x$$$$$$$$$$X;::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++x$$$$$$$$$$$$$$$X$X;::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++++$&$$$$$$$$$$$$$$$$$X$x:::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++++$&&$$$$+;X$$$$$$$XXX$XXx::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++X&&&&$X+:::;X$$$XX$$$$$$$+:::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;++++++++++++++X&&$x+;:::::::+X$$$$$$$$X+:::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;++++++++++++++X&$x+;::::::::::::::::+$$;:::::::::::::::::::::::::::::::::::\n\t;;;;;;+;;;;;;;;;;;;;;;++++++++++++++x&$x+++x+++::::;+++;::;$X;:::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;++++++++++++++x+$$XXXX$XXx++xxXXxxxxXx;;:::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;+++++++++++++++xx+$++;;:;X;:X::;;:;x:;;::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;++++++++++++++++++X;:::x+;:;+:::;x;:;:::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++++++;:::;+;::::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++++++;::::;;+;::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++++++:::;;;;;::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++++++++++:::;;;:::::::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++++++++xx;:::::::::;::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++++++;++x+::::::+;:::::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++x++xxxXXXx+::::;::::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++++++++++++++::::....:::::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;++++++++++XX++++;:;+;:.......:x;:::::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;;;+++++++++x$&&$x+;:::::;........;$$X+:::::::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;;;;+++++++x$&&&&&&&xx+::::+++.....::x$$$$$$X+;::::::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;;;;+++++xX$&&&&&&&&&&&&x+++;+;..;.::::+$$$$$$$$$$$Xx;::::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;;+++++X&&&&&&&&&&&&&&&&&X++++;:..:::::;$$$$$$$$$$$$$$$$$x;::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;+++++++$&&&&&&&&&&&&&&&&&&$+:;:::..:::::X$$$$$$$$$$$$$$$$$$$;:::::::::::::::::::::\n\t;;;;;;;;;;;;+++++++++$&&&&&&&&&&&&&&&&&&&&$;::::..::::x$$$$$$$$$$$$$$$$$$$$X;::::::::::::::::::::\n\t;;;;;;;;;;++++++++++X&&&&&&&&&&&&&&&&&&&&&&$::::..:::+$$$$$$$$$$$$$$$$$$$$$$x::::::::::::::::::::\n\t;;;;;;;;+++++++++++x$&&&&&&&&&&&&&&&&&&&&&&&X:::..::;$$$$$$$$$$$$$$$$$$$$$$$$;:::::::::::::::::::\n\t;;;;;;;;+++++++++++$&&&&&&&&&&&&&&&&&&&&&&&&$x::..:;X$$$$$$$$$$$$$$$$$$$$$$$$X:::::::::::::::::::\n\t;;;;;;;;++++++++++x&&&&&&&&&&&&&&&&&&&&&&&&&&$;:..:x$$$$$$$$$$$$$$$$$$$$$$$$$$+::::::::::::::::::\n\t;;;;;;;;;+++++++++$&&&&&&&&&&&&&&&&&&&&&&&&&&&$:..x$$$$$$$$$$$$$$$$$$$$$$$$$$$$;:::::::::::::::::\n\t;;;;;;;;;;+++++++X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X.;$$$$$$$x........:X$$$$$$$$$$$x:::::::::::::::::\n\t;;;;;;;;;;;;+++++$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$xX$$$$$$$$$$$$$$$$$$$$$$&$$$$$$X;::::::::::::::::\n\t;;;;;;;;;;;;;+++X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$+::::::::::::::::\n\t;;;;;;;;;;;;;;;+$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$::::::::::::::::\n\t;;;;;;;;;;;;;;;X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$&$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$x:::::::::::::::\n\t;;;;;;;;;;;;;;+&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&&$$$$$$$$$;::::::::::::::\n\t;;;;;;;;;;;;;;X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&&&$$$$$$$$x::::::::::::::\n\t;;;;;;;;;;;;;+$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&&&$$$$$$$$X;:::::::::::::\n\t;;;;;;;;;;;;;+X$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$X$$$$&&&$$$$$$$Xx::::::::::::::\n\t;;;;;;;;;;;;;;;;;+xXX$&&&&&&&&&&&&&&&&&&&&&&&&&&$&&$$$$$$$$$$$$$$$+;xX$XXX$x+;:::::::::::::.:.:::\n\t;;;;;;;;;;;;;;;;;+++xxxxxxx$&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$x;;+$x;+::::.:.....:....::...:::\n\t;;;;;;;;;;;;;;;;;++++++++++$&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$x++::::::::::::::::::::::::\n\t;;;;;;;;;;;;;;;;;++++++++++$&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$x++::::::::::::::::::::::::\n\t(janitor's picture)",
	//Johnny (night guard)
	"#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t#+++++++++++++++++++++++++++++-----+++++++++++++++++++++++++++++++\n\t++++++++++++++++++++++++-. .-++++++++-. .-++++++++++++++++++++++++\n\t+++++++++++++++++++++- .++++++++++++++++++. -+++++++++++++++++++++\n\t+++++++++++++++++++. ++++++++++++++++++++++++ .+++++++++++++++++++\n\t+++++++++++++++++- +++++++++++++--+++++++++++++ -+++++++++++++++++\n\t++++++++++++++++..+++++++++. -##++##+ -+++++++++..++++++++++++++++\n\t+++++++++++++++ -+++++++++ -+#+ +- ###+ +++++++++. +++++++++++++++\n\t++++++++++++++..++++++++++-+-...  -..-++++++++++++..++++++++++++++\n\t+++++++++++++- ++++++++++.-+- .-++-. -#+.++++++++++ -+++++++++++++\n\t+++++++++++++..++++++++++ -++-     .-++-.++++++++++..+++++++++++++\n\t+++++++++++++ +++++++++++ -.           - +++++++++++ +++++++++++++\n\t+++++++++++++ +++++++++++ ..          .. +++++++++++ +++++++++++++\n\t+++++++++++++ +++++++++++- ..+######+...-+++++++++++ +++++++++++++\n\t+++++++++++++..+++++++++++-..########-.-+++++++++++..+++++++++++++\n\t+++++++++++++- ++++++++++++++########++++++++++++++ ++++++++++++++\n\t++++++++++++++..++++++++++.-. +####-  -.++++++++++..++++++++++++++\n\t+++++++++++++++ -+++++++++ + ...  ... # +++++++++- +++++++++++++++\n\t++++++++++++++++ -+++  ....++...... .#+....  +++- ++++++++++++++++\n\t+++++++++++++++++ ....-#+++-+++.--.+#+++++++.... +++++++++++++++++\n\t++++++++++++++++ -+++++++++#.+-#++#-+.#++++++#++- ++++++++++++++++\n\t+++++++++++++++ -+++++++++++##++--++##++++++++##+- +++++++++++++++\n\t++++++++++++++-.++++++++++++++++--++++++++++++###+.-++++++++++++++\n\t++++++++++++++ +####++ .  .-   +--+..  .  .-++####+ ++++++++++++++\n\t+++++++++++++-.+###+++   . .-  +--+. . .  --+#+###+.-+++++++++++++\n\t+++++++++++++ +####+#++++++++++++-++++++++++##+####+ +++++++++++++\n\t+++++++++++++ ----+-###++++++++++-+++++++++###-++--- +++++++++++++\n\t#++++++++++++ -++##+####+++++++++-++++++++####-##++- +++++++++++++\n\t#+++++++++++++ .... ####+++++++++-++++++++#### .... -+++++++++++++\n\t#+++++++++++++ .... ####+++++++++-++++++++#### .... -+++++++++++++\n\t++++++++++++++ .... ####+++++++++-++++++++#### .... -+++++++++++++\n\t++++++++++++++++++-.#####++++++++-+++++++#####.-++++++++++++++++++\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t(Picture of night guard)"};
	
	printf("%s\n\n\t",person[p]);
}


void removeOpt(char A[][100], int size, int n){
	for(int i=n; i<size; i++){
    	strcpy(A[i],A[i+1]);
	}
}

int createNewFile(){
	FILE *fp;
	fp = fopen("saveFile.csv","w");
	if(fp == NULL){
		fclose(fp);
		return 1;
	}else{
		puts("File created.");
		fprintf(fp,"0\n0\n");
		fclose(fp);
		return 0;
	}
}

int save(int progress, int checkpoint, char name[100], char culprit[100], int lose){ //save progress data
    char fname[] = "saveFile.csv";
    FILE *fp;
	
    fp = fopen(fname,"w");
    if(fp == NULL){
    	fclose(fp);
    	int a = 0;
        do{/*printf("\n\t\"%s\" not found. (%d)\n\t",fname,a++);*/}while(createNewFile());
    }
    fclose(fp);
    
    //printf("\n\t\"%s\" found.\n\t",fname);
    fp = fopen(fname,"w");
    
	fprintf(fp,"%d\n%d\n%s\n",progress,checkpoint,(name)?name:"");
	
	fclose(fp);
	return 1;
}

void load(int* progress, int* checkpoint, char** name, char** culprit, int* lose){ //load progress data
	char fname[] = "saveFile.csv"; 
    FILE *fp;
	
    fp = fopen(fname,"r"); 
    if(fp == NULL) {
        //printf("\n\t\"%s\" not found.\n\t",fname);
        fp = fopen(fname,"w"); 
    }else{
        //printf("\n\t\"%s\" found.\n\t",fname);
        fscanf(fp, "%d\n%d\n", progress, checkpoint);
		*name = (char*)malloc(100 * sizeof(char));
        fscanf(fp, "%[^\n]\n",*name);
	    *culprit = (char*)malloc(100*sizeof(char));
	    fscanf(fp, "%[^\n]\n%d", *culprit, lose);
	}
    fclose(fp);
}

int loadData(Data* data){ //load log data
    char fname[] = "reportData.txt";
    FILE* fp = fopen(fname, "r");
	
    if(fp == NULL){
    	fclose(fp);
        printf("\n\t\"%s\" not found. Please get a valid file.\n", fname);
        return 1; // Indicate error (non-zero return value)
    }else{
        //printf("\n\t\"%s\" found.",fname);
        int i = 0;
        while (fscanf(fp, "%d/%d/202H %s %d:%d",
			&data[i].date.day,
			&data[i].date.month,
			data[i].employeeId,
			&data[i].time.hour,
			&data[i].time.min
		) == 5){
			i++;
            //printf("\n\t%4d | %d/%d/202H | %-12s | %d:%d\n", i, data[i].date.day, data[i].date.month,data[i].employeeId, data[i].time.hour, data[i].time.min);
        }
        //printf("\n\t%d logs loaded from file.\n", i);
        fclose(fp);
        return i;
    }
}

void display(Data data[], int max){ //display data as table
	printf("\n\t,_____________________________________________,\n\t| No   | Date      | Employee ID  | Clock-out |\n\t|------+-----------+--------------+-----------|");
    for(int i=0; i < max; i++){
        printf("\n\t| %-4d | %d/%d/202H | %-12s | %d:%02d%-4s |\n\t%s", i+1,
               data[i].date.day,
			   data[i].date.month,
               data[i].employeeId,
			   data[i].time.hour,
			   data[i].time.min,"",
			   "|------+-----------+--------------+-----------|");
    }
}

void display2(Data data[], int max){ //display custom data as table
    printf("\n\t,_____________________________________________,\n\t| No   | Date      | Employee ID  | Clock-out |\n\t|------+-----------+--------------+-----------|");
    int count = 1; //counter for displayed data
    for(int i = 0; i < max; i++){
        if(data[i].time.hour >= 19){ //check if hour is 19 or more
            printf("\n\t| %-4d | %d/%d/202H | %-12s | %d:%02d%-4s |\n\t%s", count++,
                   data[i].date.day, data[i].date.month, data[i].employeeId,
                   data[i].time.hour, data[i].time.min,"","|------+-----------+--------------+-----------|");
        }
    }
}

void display3(Data data[], int max, int num){ //display custom data as table
    printf("\n\t,_____________________________________________,\n\t| No   | Date      | Employee ID  | Clock-out |\n\t|------+-----------+--------------+-----------|");
    int count = 1; //counter for displayed data
    for(int i = 0; i < max; i++){
        if(data[i].date.day == num){ //check if hour is 19 or more
            printf("\n\t| %-4d | %d/%d/202H | %-12s | %d:%02d%-4s |\n\t%s", count++,
                   data[i].date.day, data[i].date.month, data[i].employeeId,
                   data[i].time.hour, data[i].time.min,"","|------+-----------+--------------+-----------|");
        }
    }
}

void swap(Data* a, Data* b){ //swap function to help sorting function
    Data temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortData(Data* data, int numData){ //function sort Data struct based on date and time
    for(int i = 0; i < numData - 1; i++){
        for(int j = 0; j < numData - i - 1; j++){
            if(data[j].date.month > data[j + 1].date.month){
                swap(&data[j], &data[j + 1]);
            }else if (data[j].date.month == data[j+1].date.month && data[j].date.day > data[j+1].date.day){
                swap(&data[j], &data[j + 1]);
            }else if (data[j].date.month == data[j+1].date.month && data[j].date.day == data[j+1].date.day && data[j].time.hour > data[j+1].time.hour){
                swap(&data[j], &data[j + 1]);
            }else if (data[j].date.month == data[j+1].date.month && data[j].date.day == data[j+1].date.day && data[j].time.hour == data[j+1].time.hour && data[j].time.min > data[j+1].time.min){
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}
