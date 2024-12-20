#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#include <windows.h>
#include "narrative.h"
#include "eventhandler.h"
#include "console.h"

extern int MISSION_COUNTER;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNTER;


void dialoguePerson0() {
    if (MISSION_COUNTER == 0) {
        //Barmen
         message barmen1 = {L"\nBarmen: Daha ne kadar oyalanacaksın, ozan? Burada fazladan oturmanın bir maliyeti olur, unutma."};
         message barmen2 = {L"\nBir içki daha alabilir miyim ?."};
         message barmen3 = {L"\nBarmen: Hahah, paranın olmadığını unuttun galiba."};
         message barmen4 = {L"\n\0"};

        message barmen[] = {barmen4, barmen3, barmen2, barmen1};

        for (int i = 0; i < 4; ++i) {
            sendToRightSection(barmen[i]);
        }
    }

    if (MISSION_COUNTER == 1) {
        // Sebinchi
        message seb0 = {L"(Sebinchi barın köşesinde, kılıcını masanın üzerine bırakmış oturuyor.) "};
        message seb1 = {L"\nS: Altınlar gelip geçer şimdilik elimizdekilerle yetinmeliyiz."};
        message seb2 = {L"\nSen: Peki ya o gençler? Gerçekten peşimize düşecekler mi?"};
        message seb3 = {L"\nS: Onlar tehlikeli değil. Ama o gençlerle bir kez daha karşılaşacağımızı biliyorum."};
        message seb4 = {L"\nSen: O fedailer altınları çaldı. Şimdi ne yapacağız?"};
        message seb5 = {L"\n\0"};

        message sebDiyalog[] = {seb5, seb4, seb3, seb2, seb1,seb0};

        for (int i = 0; i < 5; ++i) {
            sendToRightSection(sebDiyalog[i]);
        }
    }
}

void dialoguePerson1() {
    if (MISSION_COUNTER == 0) {
        //ayyaş
        message ayyas1={L"Ayyaş: (Gözleri yarı kapalı) Heey, sen yeni bir yüzsün. Şarkı çalar mısın? Bu yerin biraz müziğe ihtiyacı var."};
        message ayyas2={L"Sen: Belki sonra. Şimdi işim var."};
        message ayyas3 =  {L"Ayyaş: (Hafifçe güler) İş mi? Burada kimse iş yapmaz, dostum. Bir içki al ve rahatla. Dünya zaten yeterince sıkıcı."};
        message ayyas4= {L"\0"};
        message ayyas[]={ayyas4,ayyas3,ayyas2,ayyas1};

        for (int i = 0; i < 4; ++i) {
            sendToRightSection(ayyas[i]);
        }
    }
    if (MISSION_COUNTER == 1) {
        // Tüccar
        message merchantScene = {L"\n(Tüccar, küçük bir masada oturmuş, önündeki deri çantasını düzenliyor.)"};
        message merchant1 = {L"\nTüccar: Hey, sen! Yeni bir maceracı mısın? Sana uygun bir şeylerim olabilir."};
        message merchant2 = {L"\nSen: Macera mı? Sadece hayatta kalmaya çalışıyorum."};
        message merchant3 = {L"\nTüccar: Hayatta kalmak da bir sanattır, genç dostum. Ama bir gün şu haritaya göz atmak isteyebilirsin. Gördüğün gibi, kayıp hazineler sadece hikayelerde yoktur."};
        message merchantEnd = {L"\n\0"};

        message merchantDiyalog[] = {merchantEnd, merchant3, merchant2, merchant1, merchantScene};

        for (int i = 0; i < 5; ++i) {
            sendToRightSection(merchantDiyalog[i]);
            Sleep(2000);
        }

    }

}

void dialoguePerson2() {
    if (MISSION_COUNTER == 0) {
        message evsiz1= {L"Evsiz: Hey, bard! Üstündeki çanta… Ne taşıyorsun? Biraz ekmek var mı?"};
        message evsiz2= {L"Sen: Üzgünüm, hiçbir şeyim yok."};
        message evsiz3= {L"Evsiz: (Başını iki yana sallayarak) Aynen… Zaten kimsenin bir şeyi yok. Ama dikkat et, burada insanlar aç. Sen de hedef olabilirsin."};
        message evsiz4= {L"\0"};
        message evsiz[10]={evsiz4,evsiz3,evsiz2,evsiz1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(evsiz[i]);
        }
    }
    if (MISSION_COUNTER == 1) {
        // Althara
        message altharaScene = {L"\n(Althara, koyu renk peleriniyle oturmuş, elindeki kitapla ilgileniyor. Seni fark ettiğinde hafifçe gülümser.)"};
        message althara1 = {L"\nAlthara: Ah, bir ozan! Hikayelerle mi ilgilenirsin, yoksa kendi hikayeni mi yazıyorsun?"};
        message althara2 = {L"\nSen: Sanırım kendi hikayemi yazıyorum."};
        message althara3 = {L"\nAlthara: O zaman dikkat et. Bu dünyada yazılan her hikaye, bir bedel ödemeyi gerektirir. Sadece doğru bedeli ödediğinden emin ol."};
        message altharaEnd = {L"\n\0"};

        message altharaDiyalog[] = {altharaEnd, althara3, althara2, althara1, altharaScene};

        for (int i = 0; i < 5; ++i) {
            sendToRightSection(altharaDiyalog[i]);
        }

    }



}

void dialoguePerson3() {
    if (MISSION_COUNTER == 0) {
        //Garson
            message garson1={L"Garson: (Hızlıca masaların arasında dolaşırken) Dur, yeni misin sen? Ben seni daha önce burada görmedim."};
            message garson2={L"Sen: Evet, ilk kez geldim."};
            message garson3={L"Garson: O zaman dikkatli ol. Buradaki insanlar dostane görünmez ama bir yanlış yaparsan seni kapının önüne koyarlar. Ve inan bana, kapı dışarısı hiç güvenli değil."};
            message garson4={L"\0"};
            message garson[10]={garson4,garson3,garson2,garson1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(garson[i]);
        }
    }
    if (MISSION_COUNTER == 1) {
        // Finn
        message finnScene = {L"\n(Finn, heyecanla sana bakıyor, gözlerinde merak dolu bir ifade var.)"};
        message finn1 = {L"\nFinn: Sen… sen ozan mısın? Gerçekten mi? Şarkı söyler misin?"};
        message finn2 = {L"\nSen: Belki sonra. Şu an yorgunum."};
        message finn3 = {L"\nFinn: Peki, bana biraz macerandan bahseder misin? Hep dışarı çıkmak istemişimdir ama annem izin vermez."};
        message finnEnd = {L"\n\0"};

        message finnDiyalog[] = {finnEnd, finn3, finn2, finn1, finnScene};

        for (int i = 0; i < 5; ++i) {
            sendToRightSection(finnDiyalog[i]);
        }
    }
}

void dialoguePerson4() {
    if (MISSION_COUNTER == 1) {
        // 6. Ayyaş
        message drunkScene = {L"\n(6. Ayyaş, köşede dengesizce oturuyor, üzerindeki eski kıyafetlerden alkol kokusu yayılıyor.)"};
        message drunk1 = {L"\nSen: Sen hala burada ne arıyorsun?"};
        message drunk2 = {L"\n……."};
        message drunk3 = {L"\n(Cevap vermedi.)"};
        message drunkEnd = {L"\n\0"};

        message drunkDiyalog[] = {drunkEnd, drunk3, drunk2, drunk1, drunkScene};

        for (int i = 0; i < 5; ++i) {
            sendToRightSection(drunkDiyalog[i]);
        }
    }
}