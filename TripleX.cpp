    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <ctime>
    using namespace std;
    void PlayIntroduction(){

        std::cout<<" _______ _            _   _                       _     _       _____               _      \n";
        std::cout<<"|__   __| |          | \\ | |                     | |   ( )     |  __ \\             | |     \n";
        std::cout<<"   | |  | |__   ___  |  \\| |_   _ _ __ ___  _ __ | |__ |/ ___  | |__) |   _ _______| | ___ \n";
        std::cout<<"   | |  | '_ \\ / _ \\ | . ` | | | | '_ ` _ \\| '_ \\| '_ \\  / __| |  ___/ | | |_  /_  / |/ _ \\\n";
        std::cout<<"   | |  | | | |  __/ | |\\  | |_| | | | | | | |_) | | | | \\__ \\ | |   | |_| |/ / / /| |  __/\n";
        std::cout<<"   |_|  |_| |_|\\___| |_| \\_|\\__, |_| |_| |_| .__/|_| |_| |___/ |_|    \\__,_/___/___|_|\\___|\n";
        std::cout<<"                             __/ |         | |\n";
        std::cout<<"                            |___/          |_|\n\n\n";
        std::cout<<"Hello, brave knight. I am a water spirit.\n";
        std::cout<<"You must solve my puzzles in order to pass through my lake.\n";
        std::cout<<"Think you have what it takes?\n\n";
    }

    bool PlayGame(int Section){
        if(Section==1){
            std::cout<<"Welcome. You are now in section "<<Section<<std::endl;
        }
        int PuzzleA=0;
        int PuzzleB=0;
        int PuzzleC=0;
        srand(time(NULL));
        if(Section<=3){
            PuzzleA=rand()%6;
            PuzzleB=rand()%6;
            PuzzleC=rand()%6;
        }
        if(Section>=4&&Section<=10){
            PuzzleA=rand()%11;
            PuzzleB=rand()%11;
            PuzzleC=rand()%11;
        }
        if(Section>=11&&Section<=15){
            PuzzleA=rand()%11+5;
            PuzzleB=rand()%11+5;
            PuzzleC=rand()%11+5;
        }
        if(Section>=16&&Section<=20){
            PuzzleA=rand()%11+10;
            PuzzleB=rand()%11+10;
            PuzzleC=rand()%11+10;
        }
        if(Section>=21&&Section<=25){
            PuzzleA=rand()%11+15;
            PuzzleB=rand()%11+15;
            PuzzleC=rand()%11+15;
        }
        if(Section>=26&&Section<=30){
            PuzzleA=rand()%11+20;
            PuzzleB=rand()%11+20;
            PuzzleC=rand()%11+20;
        }
        if(Section>=31&&Section<=35){
            PuzzleA=rand()%11+25;
            PuzzleB=rand()%11+25;
            PuzzleC=rand()%11+25;
        }
        if(Section>=36&&Section<=40){
            PuzzleA=rand()%11+30;
            PuzzleB=rand()%11+30;
            PuzzleC=rand()%11+30;
        }
        if(Section>=40&&Section<=45){
            PuzzleA=rand()%11+40;
            PuzzleB=rand()%11+40;
            PuzzleC=rand()%11+40;
        }
        if(Section>=46&&Section<=50){
            PuzzleA=rand()%51+50;
            PuzzleB=rand()%51+50;
            PuzzleC=rand()%51+50;
        }


        int PuzzleSum=PuzzleA+PuzzleB+PuzzleC;
        int PuzzleProduct=PuzzleA*PuzzleB*PuzzleC;
        int GuessA, GuessB, GuessC;
        std::cout<<"You must deduce three numbers to continue.\n";
        std::cout<<"-The numbers add up to "<<PuzzleSum<<"\n";
        std::cout<<"-The product of the numbers is "<<PuzzleProduct<<"\n";
        std::cin>>GuessA>>GuessB>>GuessC;
        int GuessSum=GuessA+GuessB+GuessC;
        int GuessProduct=GuessA*GuessB*GuessC;
        std::cout<<"Your guess is..."<<GuessA<<", "<<GuessB<<", "<<GuessC<<"?\n"<<"That is...\n";
        std::cout<<"...\n...\n";
        if((GuessProduct==PuzzleProduct)&&(GuessSum==PuzzleSum)){
            std::cout<<"...correct. You may pass through this section of my lake.\n\n\n\n";
            std::cout<<"Welcome. You are now in section "<<Section<<".\n";
            return true;
        }
        else{
            std::cout<<"...incorrect.\n\n\n\n";
            std::cout<<"You are still in section "<<Section<<".\n";
            return false;
        }
    }

    int main(){
        int Level=1;
        int MaxLevel=45;
        printf("Would you like to start from the beginning?\n");
        string AnswerZero;
        std::cin>>AnswerZero;
        transform(AnswerZero.begin(), AnswerZero.end(), AnswerZero.begin(), ::toupper);
        if(AnswerZero=="NO"){
        std::cout<<"What section would you like to start from?\n";
        std::cin>>Level;
        std::cin.clear();
        std::cin.ignore();
        }
        PlayIntroduction();
        while(Level<=MaxLevel){
            bool bLevelComplete=PlayGame(Level);
            std::cin.clear();//clears any errors
            std::cin.ignore();//discards the buffer (unsure what that means)
            if(bLevelComplete){
                ++Level;
            }
        }
        printf("You've reached the shore. Would you like to cross five extra sections?\n");
        string AnswerOne;
        std::cin>>AnswerOne;
        transform(AnswerOne.begin(), AnswerOne.end(), AnswerOne.begin(), ::toupper);
        if(AnswerOne=="YES"){
            printf("Good luck. You'll need it.");
            MaxLevel=50;
            while(Level<=MaxLevel){
                bool bLevelComplete=PlayGame(Level);
                std::cin.clear();//clears any errors
                std::cin.ignore();//discards the buffer (unsure what that means)
                if(bLevelComplete){
                    ++Level;
                }
            }
        }
        printf("Congratulations, you've successfully solved my puzzles and crossed my lake.\n");
        printf("Onward, brave knight! Your quest awaits!");
        return 0;
    }