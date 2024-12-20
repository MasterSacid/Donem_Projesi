#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"

void bolum_2_savas() {
    HANDLE STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE STDIN = GetStdHandle(STD_INPUT_HANDLE);

    dialog dialogues1[] = {
        {{L"\nAdam: Sana bir iş teklif ediyorum. Bunun kolay olmadığını baştan söyleyeyim. Ama ödül, karşılaşacağın tehlikeye değebilir."}, 1000, 1},
        {{L"\nOmzundaki çantayı sıkıca kavrayarak adama bakıyorsun. Paraya muhtaç olduğun bir gerçek. Seçeneğin yok."}, 1000, 1},
        {{L"\nSen: Peki, nedir bu iş?"}, 1000, 1},
        {{L"\nAdam: Şehirden yeni ayrılmış bir grup tüccar var. Yanlarında değerli mallar taşıyorlar. Bizim bu malları ele geçirmemiz gerekiyor."}, 1000, 1},
        {{L"\nSen: Bizim mi? Yani sen de mi geleceksin?"}, 1000, 1},
        {{L"\nAdam hafifçe gülüyor."}, 1000, 1},
        {{L"\nAdam: Hayır, bu işi sen halledeceksin. Ben burada kalıp dikkatleri dağıtacağım. Sen, tüccarları yolun ortasında durduracak ve mallarını alacaksın."}, 1000, 1},
        {{L"\nSen: Tek başıma mı? Hiç savaşmadım ki!"}, 1000, 1},
        {{L"\nAdam: Savaşmaya niyetlenme zaten. Doğru zamanı kollarsan işini sessizce halledebilirsin. Ama işler sarpa sararsa… işte o zaman doğaçlama yeteneklerini göstermelisin."}, 1000, 1},
        {{L"\nAdam elini belindeki küçük bir haritaya atar ve üzerine işaret koyarak sana uzatır."}, 1000, 1},
        {{L"\nAdam: İşte burada, orman yoluna girdikleri nokta. Çok uzak değil. Onları orada yakalarsan şehirden hâlâ fazla uzaklaşmamış olacaklar. Harekete geçmek için fazla vaktin yok."}, 1000, 1},
        {{L"\nHaritaya baktığında işaretlenen yerin, dar bir patikanın başladığı nokta olduğunu görüyorsun. Orman yoğun görünüyor ve gölgeler oldukça ürkütücü. Ama başka seçeneğin yok."}, 1000, 1},
        {{L"\nBir süre sonra, barda adamın yanından ayrılıp gösterdiği yola doğru yürümeye başlıyorsun."}, 1000, 1},
        {{L"\nPatikanın kenarına ulaştığında durup etrafı inceliyorsun. Yolun karşısındaki ağaçlar ve çalılar sık. Çalıların arasına saklanarak ilerlemeye başlıyorsun."}, 1000, 1},
        {{L"\nUzaktan boğuk sesler duyuyorsun. Sesleri takip ederek bir noktaya kadar yaklaşıyorsun ve sonunda onları görüyorsun: İki tüccar, bir araba ve 2 koruma."}, 1000, 1},
        {{L"\nTüccarlar, arabanın üzerindeki yükleri kontrol ediyor. Koruma ise elleri kılıcının kabzasında, tetikte bir şekilde etrafı izliyor. Onlara birkaç metre mesafedesin, ağaçların arasından dikkatlice izliyorsun."}, 1000, 1},
        {{L"\nKoruma 1: Aben, yolumuz uzun. Ben iki dakka şu çalıda işimi halledeyim."}, 1000, 1},
        {{L"\nOlamaz! Bir koruma senin bulunduğun çalıya doğru geliyor."}, 1000, 1},
        {{L"\n\"Ahhh hiç vakit yok. Ne yapacağım?\""}, 1000, 1},
        {{L"\0"}, 10, 1}
    };

    wchar_t sorgu1[] = {L"Korumanın dikkatini dağıtmak için bir bahane uydur."};
    wchar_t secenekler1[2][300] = {
        L"Bahane1: \"Ah, sonunda bir insan! Çok önemli bir şey sormam gerekiyor. Buradan geçen pembe bir tavşan gördünüz mü? Onu takip ediyordum ama bir anda kayboldu!\"",
        L"Bahane2: \"Dur! Bana zarar verme! Ben… ben ormanda kayboldum ve büyülü bir kazanı arıyorum. Dedem bu kazanın dilekleri yerine getirdiğini söyledi!\""
    };
    system("cls");

    printSequence(dialogues1);
    dialogChoice(sorgu1, secenekler1, 2);

    dialog dialogues2[] = {
        {{L"\nKoruma 1: Sen bizimle dalga mı geçiyorsun!"}, 1000, 1},
        {{L"\nAben: Hey, ne oluyor orada!"}, 1000, 1},
        {{L"\nKoruma: (Kılıcını çeker.) Bence bu işi uzatmadan halledelim, efendim. Fazla konuştu bile."}, 1000, 1},
        {{L"\nTüccar 1: Demek bizi aptal yerine koyuyorsun, ha? Söylesene, aslında neyin peşindesin?"}, 1000, 1},
        {{L"\nSavaş başlar..."}, 1000, 1},
        {{L"\0"}, 10, 1}
    };

    printSequence(dialogues2);

    //Savaşma fonksiyonu burada geliyor


    dialog dialogues3[] = {
        {{L"\nSavaşı kazanırsın."}, 1000, 1},
        {{L"\nBara dönersin."}, 1000, 1},
        {{L"\nKapıyı açıp içeri girersin."}, 1000, 1},
        {{L"\nAdam: Hah! Başardığını biliyordum. Pekala, ganimet nerede? Şimdi bölüşebiliriz."}, 1000, 1},
        {{L"\nSen: Bölüşebilir miyiz? Şaka mı yapıyorsun? Ben orada canımı dişime takarken sen burada oturup içki içiyordun!"}, 1000, 1},
        {{L"\nAdam: Ve ben sana bu işi verdim. O haritayı göstermeseydim şimdi burada olmazdın, değil mi? O yüzden hakkımı almayı düşünüyorum."}, 1000, 1},
        {{L"\nSen: Hakkını mı? Hakkını mı? Tüm işi ben yaptım! Korumalara karşı savaştım, ganimeti topladım. Sen burada oturup bana akıl vermekten başka ne yaptın?"}, 1000, 1},
        {{L"\nAdam: Bak, bu işi sana ben ayarladım. Eğer ganimeti paylaşmazsan, burada pek hoş olmayan bir sahne çıkabilir."}, 1000, 1},
        {{L"\nÇATT!!!!"}, 1000, 1},
        {{L"\nAdam: Kapıya ne oldu öyle ya…"}, 1000, 1},
        {{L"\nLoş ışığın altında uzun boylu, güçlü bir kadın içeri girer. Siyah deri bir zırh giymiş, belinde uzun bir pala taşıyor. Yüzündeki ifadeyle tüm dikkatleri üzerine çeker."}, 1000, 1},
        {{L"\nSebinchi: Bir içki ver, ama bu sefer kaliteli bir şey olsun. Bu barın şarapları rezalet."}, 1000, 1},
        {{L"\nKadın, ağır adımlarla yaklaşır. Gözlerini bir süre üzerinizde gezdirdikten sonra hafifçe alaycı bir gülümseme belirir."}, 1000, 1},
        {{L"\nSebinchi: (İkisine de bakarak) Ne oluyor burada? Çocuk gibi kavgalar mı ediyorsunuz? Yoksa iki yeteneksiz birbirine diş mi gösteriyor?"}, 1000, 1},
        {{L"\nAdam: Bu seni ilgilendirmez, Sebinchi."}, 1000, 1},
        {{L"\nSebinchi: Her şey beni ilgilendirir. Özellikle bu şehirde kimin ne yaptığını öğrenmek benim işim. Şimdi, anlat bakalım… nedir bu ganimet meselesi?"}, 1000, 1},
        {{L"\nDurum açıklanır."}, 1000, 1},
        {{L"\nSebinchi: (Sert bir sesle) İkiniz de oldukça acemice davranıyorsunuz. Ganimet kavgaları mı yapıyorsunuz? Çocuk oyuncağı bunlar. Ama neyse… Şimdi sakinleşin. (Bize bakar) Sen. Yeni bir iş yapacaksın. Yanında ben de olacağım. Bu adamdan daha fazla fayda sağlayacağın kesin."}, 1000, 1},
        {{L"\nAdam: Hey! Bu işi ben ayarladım, bu benim bilgim!"}, 1000, 1},
        {{L"\nSebinchi: Hahahahah! Bilgini paylaşmazsan, yalnız kalırsın. Bard, karar senin. Ama şunu unutma: Yalnız gidersen hayatta kalamazsın."}, 1000, 1},
        {{L"\nAdam: Peki, peki! Bir bilgi daha var. Şehirden ayrılan başka bir grup tüccar daha var. Ama bunlar çok daha tehlikeli. Koruma değil, paralı askerler kullanıyorlar. Eğer bu işi yapacaksan, Sebinchi gibi birine ihtiyacın olacak."}, 1000, 1},
        {{L"\nSebinchi: Hazır olduğunda beni bul, yolculuğa çıkacağız."}, 1000, 1},
        {{L"\nSebinchi: Yola çıkmaya hazır mısın, küçük ozan? Ama beni hayal kırıklığına uğratma. Yoksa bu şehirde uzun süre barınamazsın."}, 1000, 1},
        {{L"\0"}, 10, 1}
    };
    printSequence(dialogues3);


}
