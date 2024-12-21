#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part6.h"
#include "../include/combat.h"
#include "../include/character.h"

character fedai1 = {
    .name = L"fedai1",
    .level = 4,
    .health = 20,
    .stat = {10,5,10,5,10,5},
    .currency = 50,
};
character fedai2 = {
    .name = L"fedai2",
    .level = 4,
    .health = 20,
    .stat = {10,5,10,5,10,5},
    .currency = 50,
};
character missChance = {
    .name = L"Miss Chance",
    .level = 4,
    .health = 20,
    .stat = {10,5,10,5,10,5},
    .currency = 50,
};
character hanci6 = {
    .name = L"Hancı",
    .level = 4,
    .health = 20,
    .stat = {20,5,10,5,20,5},
    .currency = 50,
};
character finn = {
    .name = L"Finn",
    .level = 4,
    .health = 20,
    .stat = {700,5,10,5,20,5},
    .currency = 50,
};

void part6() {

    dialog dialogues6[] = {
        {{L"\nSessizlik hâkimdir; herkesin yüzünde bir gerginlik var."}, 1000, 1},
        {{L"\nSebinchi masanın başına oturuyor ve kılıcını yanına koyuyor."}, 1000, 1},
        {{L"\nSebinchi: Pekâlâ. Haydutlar bir süreliğine etkisiz hâle getirildi. Ama bu iş burada bitmedi. Daha büyük balıklar var."}, 1000, 1},
        {{L"\nKapı açılır, tanıdık bir figür içeri girer. Adam, çantasından bir harita çıkararak masaya bırakır."}, 1000, 1},
        {{L"\nAdam: Daha önce bahsettiğim haydutların liderleri, şehir dışında bir sığınakta buluşuyorlar. Eğer onları etkisiz hale getirirseniz, Broski ve Lyria’nın işi çok daha kolaylaşır."}, 1000, 1},
        {{L"\nLyria: Bu, köyümüzü yeniden inşa etme şansımız olabilir. Gidelim!"}, 1000, 1},
        {{L"\nSebinchi: Doğru. Ama bu sefer işimizi çabuk ve sessizce halledeceğiz. Yanımızda gereksiz dikkat çeken biri olmadan."}, 1000, 1},
        {{L"\nSen: Gereksiz mi? Ben de geliyorum."}, 1000, 1},
        {{L"\nSebinchi: Hayır, küçük ozan. Artık sana güvenemem. Bizimle kalırsan sadece dikkat çekeceksin. Bu iş bize ait."}, 1000, 1},
        {{L"\nSen: Ama size yardım edebilirim! Lir—"}, 1000, 1},
        {{L"\nSebinchi: (Kaşlarını çatar) Yeter! Senin sırrın başımıza bela olabilir. Burada kal ve bizi bekle. Eğer sağ kalırsak geri döneriz."}, 1000, 1},
        {{L"\nSözlerini bitirir ve Broski ile Lyria’yı yanına alarak hana veda eder."}, 1000, 1},
        {{L"\nBarın ağır havasında oturuyorsunuz, barmen yanınıza gelir."}, 1000, 1},
        {{L"\nBarmen: Senin burada kalman belki de daha iyi. Sebinchi’nin doğru yaptığına inanıyorum. Ama biraz dinlen. Sana bir içecek hazırlayayım."}, 1000, 1},
        {{L"\nBaşını sallayarak masaya oturdun. ÇATT! Kapı açıldı."}, 1000, 1},
        {{L"\nNe kadar da zarif bir kadın! Kadın masaya oturdu ve garsondan bir şeyler sipariş etti."}, 1000, 1},
        {{L"\nMissChansing: Burada kalacak bir oda arıyorum. Bu bölge oldukça ilginçmiş. Yardımcı olabilir misiniz?"}, 1000, 1},
        {{L"\nSen: (Gülümseyerek) Tabii, bu bölgede ne arıyorsunuz?"}, 1000, 1},
        {{L"\nMissChansing: Sadece… biraz iş. Buraları keşfetmek istiyorum."}, 1000, 1},
        {{L"\nİçkileri ve yiyecekleri hazırlamak için mutfağa gidiyorsunuz."}, 1000, 1},
        {{L"\nHancı, masadaki bir kâğıdı işaret ediyor."}, 1000, 1},
        {{L"\nHancı: Kadın bir ödül avcısı. Dikkatli ol. Hemen harekete geçmeliyiz."}, 1000, 1},
        {{L"\nSen: (Fısıldayarak) Bu kesin mi?"}, 1000, 1},
        {{L"\nHancı: (Sert bir bakışla) Evet. Onu izle. Sessizce hazır ol."}, 1000, 1},
        {{L"\nHancı mutfaktan bir bıçak aldı ve garsona göz kırptı."}, 1000, 1},
        {{L"\0"}, 10, 1},

    };

    wchar_t sorgu1[] = {L"Bir hamle yap"};
    wchar_t secenekler1[1][300] = {
        L"Sessizce hazırlan ve bekle.",
    };

    printSequence(dialogues6);
    dialogChoice(sorgu1, secenekler1, 1);
    system("cls");
    Sleep(100);

    // Savaşı çağır ve kazan
    if (initCombat((pCharacter[]){&finn,&hanci6},2,(pCharacter[]){&missChance,&fedai1,&fedai2},3)==0) {
        return;
    }

    dialog dialoguesPostChoice[] = {
        {{L"\nMissChansing: (Yerde, zor nefes alırken) Bu lir… senin başını belaya sokacak, ozan. Onlar geliyor…"}, 1000, 1},
        {{L"\nO gelen Finn mi ?"}, 1000, 1},

        {{L"\nFinn: Sebinchi! Broski! Lyria! Onlar… onlar tuzağa düştü! Başları belada! Hemen bir şey yapmalıyız!"}, 1000, 1},
        {{L"\nBarmen, garsona ve sana bakar."}, 1000, 1},
        {{L"\nBarmen: Saklanmayı bıraksan iyi olur, ozan. Görünüşe göre zamanı geldi."}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialoguesPostChoice);
}
