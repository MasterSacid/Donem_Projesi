#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part3.h"
#include "../include/combat.h"
#include "../include/character.h"

character paidSoldier = {
    .name = L"Paralı Asker1",
    .level = 2,
    .health = 40,
    .stat = {10,5,5,5,5,5},
    .currency = 50,
};
character paidSoldier1 = {
    .name = L"Paralı Asker2",
    .level = 2,
    .health = 40,
    .stat = {5,5,5,5,5,5},
    .currency = 50,
};
character sebinchi = {
    .name = L"Sebinchi",
  .level = 2,
  .health = 50,
  .stat = {20,5,10,5,16,5},
  .currency = 50,
};
character lyria = {
    .name = L"Kız",
    .level = 2,
    .health = 50,
    .stat = {10,5,10,5,16,5},
    .currency = 50,
};
character broski = {
    .name = L"oğlan",
    .level = 2,
    .health = 50,
    .stat = {10,5,10,5,16,5},
    .currency = 50,
};



void part3() {

    dialog dialogues3_part1[] = {
        {{L"\nSebinchi: \"Hadi bakalım, küçük ozan. Şimdi yeteneklerini göstermenin zamanı. Ama unutma, eğer beni hayal kırıklığına uğratırsan, bu şehirde barınamazsın.\""}, 1000, 1},
        {{L"\nOmzundaki çantanı sıkıca kavrayıp Sebinchi’yi takip ediyorsun. Yürüyüşünüz, loş orman yollarında sessizlik içinde ilerliyor."}, 1000, 1},
        {{L"\nOnun adımları kararlı ve dengeli. Çevresine göz gezdirişi, her an bir tehlikeyle karşılaşabileceğini bilen birinin tavrı. Bu tedirgin edici bir sessizlik."}, 1000, 1},
        {{L"\n..."}, 2000, 1},
        {{L"\nSen: \"Sebinchi, bu adam kimdi? Barın köşesinde oturan o garip adam. Onu nereden tanıyorsun?\""}, 1000, 1},
        {{L"\nSebinchi: (omuz silkerek) \"O, sadece işini bilen biri. Daha doğrusu, bu şehrin pis işlerini ayarlayan adamlardan biri. Kimse onu sevmez ama herkes ona ihtiyaç duyar.\""}, 1000, 1},
        {{L"\nSen: \"Peki, neden böyle bir iş teklif etti? Yani, neden kendisi yapmadı?\""}, 1000, 1},
        {{L"\nSebinchi: (Alaycı bir tonla) \"Çünkü onun işi risk almak değil, riski başkalarına devretmek. Sana bunu yapmadığını mı düşünüyorsun?\""}, 1000, 1},
        {{L"\nSen: \"Peki ya sen? Sen neden bu işin içindesin? Bu şehirden kurtulmak istemiyor musun?\""}, 1000, 1},
        {{L"\nSebinchi: \"Ben bu şehirde kalmayı seçtim çünkü bu şehrin bana ihtiyacı var. Ama bu hikayeyi duymak istediğinden emin misin?\""}, 1000, 1},
        {{L"\nSen: \"Evet.\""}, 1000, 1},
        {{L"\nSebinchi: (Kısa bir gülüşle) \"Şimdilik yeteneklerini göstermeye odaklan. Hikayeler sonra gelir.\""}, 1000, 1},
        {{L"\nBir süre daha yürüdükten sonra, ağaçların arasından tüccarların kampını görüyorsunuz."}, 1000, 1},
        {{L"\nİki paralı asker ateş başında oturuyor. Tüccarlar ahşap arabalarının üzerindeki malları kontrol ediyorlar."}, 1000, 1},
        {{L"\nSebinchi, bir ağacın gövdesine yaslanır ve kılıcını çıkararak hafifçe gülümser."}, 1000, 1},
        {{L"\nSebinchi: \"Plan basit. Ben dikkatlerini dağıtacağım, sen de malları alacaksın. Ama işler ters giderse, savaşa hazır ol. Çünkü ben seni kurtarmam.\""}, 1000, 1},
        {{L"\nSen: \"NASI YANİ!\""}, 1000, 1},
        {{L"\nSebinchi: \"Bu işte kimseye güvenemezsin, ozan. Bana bile. Ama öğrenmek için zamanın var.\""}, 1000, 1},
        {{L"\nSebinchi adımlarını sessizce atarak kampın kenarına yaklaşır."}, 1000, 1},
        {{L"\nSebinchi: \"Hey! Hey! Siz aptallar! Tüccar mallarını teslim etsin, yoksa bu gece son geceniz olur!\""}, 3000, 1},
        {{L"\nTam bu sırada sen, kampın diğer tarafından altınların olduğu çadıra doğru sessizce ilerlersin."}, 1000, 1},
        {{L"\nSen: \"AHA! İşte fırsat bu fırsat!\""}, 1000, 1},
        {{L"\nParalı Asker: \"Orada biri var! Dur!\""}, 1000, 1},
        {{L"\nSebinchi hızla harekete geçer ve paralı askere saldırır."}, 1000, 1},
        {{L"\nSebinchi: \"Savaşa hazır ol, küçük ozan!\""}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    //printSequence(dialogues3_part1);
    initCombat((pCharacter[]){&sebinchi},1,(pCharacter[]){&paidSoldier,&paidSoldier1},2);
    system("cls");
    dialog araDialog[]= {
        {{L"Gelmeye devam ediyorlar!"}, 3000, 1},
    };
    paidSoldier.health=40,
    paidSoldier1.health=40;
    paidSoldier.currency=10;
    paidSoldier1.currency=10;
    printSequence(araDialog);
    initCombat((pCharacter[]){&sebinchi},1,(pCharacter[]){&paidSoldier,&paidSoldier1},2);


    // İlk savaşı çağırıyoruz

    dialog dialogues3_afterFirstBattle[] = {
        {{L"\nSavaşı kazandın! Altınları alıp dönüyorsunuz."}, 1000, 1},
        {{L"\nHey nereye böyle!\""}, 1000, 1},
        {{L"\nKarşında biri uzun boylu, kaslı bir adam duruyor. Omuzlarında ağır bir zırh taşıyor, sırtında devasa bir balta asılı."}, 1000, 1},
        {{L"\nYüzündeki sert ifadeye rağmen, gözlerinde belli belirsiz bir tedirginlik var."}, 1000, 1},
        {{L"\nDiğeri ise zarif görünümlü, zeki bakışlı bir kız. Elinde kısa bir değnek taşıyor ve çevresine hakimiyet sergiliyor."}, 1000, 1},
        {{L"\nOğlan: \"Durun bakalım! Bu kadar altını taşımak tehlikeli olabilir, dostlar. Onları bize bırakın, biz güvenle koruruz.\""}, 1000, 1},
        {{L"\nSen: \"Siz de kimsiniz? Ne hakla önümüzü kesiyorsunuz?\""}, 1000, 1},
        {{L"\nKız: (Sakin ve soğuk bir tonla) \"Bu sorunun cevabı seni ilgilendirmez. Ama cevabı bilmek istiyorsan, altınları bırakıp gitmelisin.\""}, 1000, 1},
        {{L"\nSebinchi: \"Ahhahahahhh! Siz bu işi ciddiye alıyor musunuz? Çocuklar, evinize dönün. Gerçek savaşçılarla karşılaşmak istemezsiniz.\""}, 1000, 1},
        {{L"\nOğlan: (Adım atarak) \"Evimize dönmek mi? Hayır, bu altınlarla eve döneceğiz. Bu gece bizim gecemiz olacak!\""}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues3_afterFirstBattle);

    // İkinci savaşı çağırıyoruz
    initCombat((pCharacter[]){&sebinchi},1,(pCharacter[]){&lyria,&broski},2);


    dialog dialogues3_afterSecondBattle[] = {
        {{L"\nZafer senin! Tam o sırada bir grup haydut çetesi ormandan fırlayarak kampa gelir."}, 1000, 1},
        {{L"\nTüm altınları toplarlar ve kızla oğlanı yanlarına alırlar. Uzaklaşmaya başlarlar."}, 1000, 1},
        {{L"\nSebinchi: (Sinirle kılıcını yere saplar) \"Harika! Şimdi o aptalları kovalamak zorunda kalacağız.\""}, 1000, 1},
        {{L"\nOğlan: (Dişlerini sıkarak) \"Görüşeceğiz. Ama bu son olmayacak.\""}, 1000, 1},
        {{L"\nKız: \"Haddini aşma. Şimdi git, ama bizi unutma.\""}, 1000, 1},
        {{L"\nElinizde sadece 5 kese altın kaldı.   \""}, 1000, 1},
        {{L"\nHana geri dönerken şunları düşünüyorsun:"}, 1000, 1},
        {{L"\nBu şehirde herkes kendi hayatta kalma mücadelesini veriyor"}, 1000, 1},
        {{L"\nve sen de bu mücadelenin tam ortasındasın."}, 2000, 1},

        {{L"\nHana döndünüz.\""}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues3_afterSecondBattle);
}
