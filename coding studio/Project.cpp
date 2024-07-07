#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct{
	char name[200];
	int damage;
	int maxHealth;
}classes;

typedef struct{
	char name[200];
	int damage;
	int maxHealth;
	int expGained;
	int goldGained;
}monster;

int isNew = false;
monster monsters[] =  {
					{
						"Goblin",
						5,
						20,
						10,
						5
					},
					{
						"Orc",
						3,
						25,
						12,
						7
					}
					,{
						"Wizard",
						10,
						15,
						15,
						10
					}
					};
					
classes _class[] =  {
					{
						"Warrior",
						5,
						150
					},
					{
						"Rogue",
						10,
						75
					}
					,{
						"Archer",
						7,
						100
					}
					};

typedef struct{
	char name[200];
	classes _class;		
	int exp;
	int level;
	int gold;
	int health;
}character;

character playerCharacter;

classes loadClass(char c[]){
	if(strcmp(c, "Warrior") == 0){
		playerCharacter._class = _class[0];
	}
	else if(strcmp(c, "Rogue") == 0){
		playerCharacter._class = _class[1];
	}
	else{ //Archer
		playerCharacter._class = _class[2];
	}
	return playerCharacter._class;
}

void saveAccount(){
	FILE *fp;
	fp = fopen("account.txt", "w");
	fprintf(fp, "%s#%s#%d#%d#%d#%d#", 
			playerCharacter.name,
			playerCharacter._class.name,
			playerCharacter.exp,
			playerCharacter.level,
			playerCharacter.gold,
			playerCharacter.health);
	fclose(fp);
}

void loadAccount(){
	FILE *fp;
	fp = fopen("account.txt", "r");
	char tempclass[200];
	
	if(fp == NULL){
		isNew = true;
		fclose(fp);
		return;
	}
	fscanf(fp, "%[^#]#%[^#]#%d#%d#%d#%d#", 
			playerCharacter.name,
			tempclass,
			&playerCharacter.exp,
			&playerCharacter.level,
			&playerCharacter.gold,
			&playerCharacter.health);
	fclose(fp);
	loadClass(tempclass);
}

void newGame(){
	char tempclass[200];
	
	printf("Input your character's name : ");
	scanf("%s", playerCharacter.name); getchar();
	
	do{
		printf("Choose your class[Warrior|Rogue|Archer] : ");
		scanf("%s", tempclass);	getchar();
	}while(strcmp(tempclass, "Warrior") == 1 &&
			strcmp(tempclass, "Rogue") == 1 &&
			strcmp(tempclass, "Archer") == 1);
	playerCharacter.exp = 0;
	playerCharacter.level = 1;
	playerCharacter.gold = 0;
	
	playerCharacter.health = loadClass(tempclass).maxHealth;
}

void firstMenu(){
	int input;
		
	do{
		printf("1. Start New Game\n");
		if(!isNew)
			printf("2. Continue Game\n");
			
		printf(">> ");
		scanf("%d", &input); getchar();
		switch(input){
			case 1:
				newGame();	
			break;
		}
	}while(input > (isNew == true ? 1 : 2) || input < 1);
}

void fight(monster m){
	int input;
	
	int exp = m.expGained;
	int gold = m.goldGained;
	int damage = m.damage;
	int health = m.maxHealth;
	char name[200];
	strcpy(name, m.name);
	
	do{
		system("cls");
		printf("%s\nHealth : %d\nDamage : %d\n\n", name, health, damage);
		printf("%s\nHealth : %d\nDamage : %d\n\n", playerCharacter.name,
													playerCharacter.health,
													playerCharacter._class.damage);
		printf("1. Attack\n");
		printf("2. Run\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
				
		switch(input){
			case 1:
				health -= playerCharacter._class.damage;
				if(health <= 0){ //Player win
					playerCharacter.gold += gold;
					playerCharacter.exp += exp;
					printf("You won!\nYou gained %d gold(s) and %d exp(s)\n", gold, exp);
					if(playerCharacter.exp >= 100){
						printf("You've leveled up!\n");
						playerCharacter.exp -= 100;
						playerCharacter.level += 1;
					}
					printf("Press any key to continue...");
					getchar();
					return;
				}
				playerCharacter.health -= damage;
				if(playerCharacter.health <= 0){ //Player lose
					playerCharacter.gold = 0;
					playerCharacter.exp = 0;
					playerCharacter.health = playerCharacter._class.maxHealth;
					printf("You lose!\nYou lost all your golds and exps\nPress any key to continue...");
					getchar();
					return;
				}
			break;
			case 2:
				printf("You ran away!");
				getchar();
				return;
		}
	}while(true);
}

void fightMenu(){
	int input;
	do{
		system("cls");
		printf("Fight Menu\n==========\n");
		printf("1. Goblin\n");
		printf("2. Orc\n");
		printf("3. Wizard\n");
		printf("4. Back\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
		
		switch(input){
			case 1:
				fight(monsters[0]);
			break;
			case 2:
				fight(monsters[1]);
			break;
			case 3:
				fight(monsters[2]);
			break;
		}
	}while(input != 4);
}

void heal(){
	int gold = playerCharacter.gold;
	int healPrice = 20;
	
	if(playerCharacter.health == playerCharacter._class.maxHealth){
		printf("You're already at max health!\n");
	}
	else if(gold >= healPrice){
		int input;
		do{
			printf("Do you want to heal yourself for %d golds ?\n", healPrice);
			printf("1. Yes\n2. No\n>> ");
			scanf("%d", &input); getchar();
		}while(input != 1 && input != 2);
		
		if(input == 2){
			printf("Press any key to continue...");
			getchar();
			return;
		}
		
		playerCharacter.health = playerCharacter._class.maxHealth;
		playerCharacter.gold -= healPrice;
		printf("Healed!!\n");
	}
	else
		printf("You don't have enough gold!\n");
		
	printf("Press any key to continue...");
	getchar();
}

int main(){
	
	loadAccount();
	int input;
	
	firstMenu();
	
	do{
		system("cls");
		printf("%s's Status\n==========\n", playerCharacter.name);
		printf("Level %d\nClass : %s\nGold : %d\nExp : %d/100\nHealth : %d/%d\n", 
						playerCharacter.level,
						playerCharacter._class.name,
						playerCharacter.gold, playerCharacter.exp,
						playerCharacter.health, playerCharacter._class.maxHealth);
		printf("1. Fight\n");
		printf("2. Heal\n");
		printf("3. Save\n");
		printf("4. Quit\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
		
		switch(input){
			case 1:
				fightMenu();
				break;
			case 2:
				heal();
				break;
			case 3:
				saveAccount();
				printf("Saved Successfully!!\nPress any key to continue..."); 
				getchar();
				break;
		}
	}while(input != 4);
	
	return 0;
}
