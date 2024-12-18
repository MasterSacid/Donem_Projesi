#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "../include/narrative.h"

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
}
