#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#include <windows.h>
#include "narrative.h"
#include "eventhandler.h"
#include "console.h"


void dialoguePerson0(int missionC, int* rightSideMessageCounter,message text[]) {
    if (missionC == 0) {
        //Barmen
         message barmen1 = {L"\nBarmen: Daha ne kadar oyalanacaksın, ozan? Burada fazladan oturmanın bir maliyeti olur, unutma."};
         message barmen2 = {L"\nBir içki daha alabilir miyim ?."};
         message barmen3 = {L"\nBarmen: Hahah, paranın olmadığını unuttun galiba."};
         message barmen4 = {L"\n\0"};

        message barmen[] = {barmen1, barmen2, barmen3, barmen4};

        for (int i = 0; i < 4; ++i) {
            sendToRightSection(text, rightSideMessageCounter, &barmen[i]);
        }
    }
}

void dialoguePerson1(int missionC,int* rightSideMessageCounter) {
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //ayyaş

        message ayyas1={L"Ayyaş: (Gözleri yarı kapalı) Heey, sen yeni bir yüzsün. Şarkı çalar mısın? Bu yerin biraz müziğe ihtiyacı var."};
        message ayyas2={L"Sen: Belki sonra. Şimdi işim var."};
        message ayyas3 =  {L"Ayyaş: (Hafifçe güler) İş mi? Burada kimse iş yapmaz, dostum. Bir içki al ve rahatla. Dünya zaten yeterince sıkıcı."};
        message ayyas4= {L"\0"};
    message ayyas[]={ayyas1,ayyas2,ayyas3,ayyas4};

    for (int i = 0; i < 4; ++i) {
        sendToRightSection(ayyas,rightSideMessageCounter,&ayyas[i]);
    }
}

void dialoguePerson2(int missionC) {
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    message evsiz[10]={};
      message evsiz1= {L"Evsiz: Hey, bard! Üstündeki çanta… Ne taşıyorsun? Biraz ekmek var mı?"};
      message evsiz2= {L"Sen: Üzgünüm, hiçbir şeyim yok."};
      message evsiz3= {L"Evsiz: (Başını iki yana sallayarak) Aynen… Zaten kimsenin bir şeyi yok. Ama dikkat et, burada insanlar aç. Sen de hedef olabilirsin."};

}

void dialoguePerson3(int missionC) {
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    message garson[10]={};
        message garson1={L"Garson: (Hızlıca masaların arasında dolaşırken) Dur, yeni misin sen? Ben seni daha önce burada görmedim."};
        message garson2={L"Sen: Evet, ilk kez geldim."};
        message garson3={L"Garson: O zaman dikkatli ol. Buradaki insanlar dostane görünmez ama bir yanlış yaparsan seni kapının önüne koyarlar. Ve inan bana, kapı dışarısı hiç güvenli değil."};

}