#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part4.h"

void part4() {

    dialog dialogues4_part1[] = {
        {{L"\nHanın içerisi tanıdık bir sıcaklıkla dolu."}, 1000, 1},
        {{L"\nBarmen, masasında müşterilere içki dağıtıyor, Sebinchi ise köşede oturmuş, kılıcını yavaşça masaya koymuş dinleniyor."}, 1000, 1},
        {{L"\nSebinchi seni fark etti ve hafif bir baş selamıyla seni yanına çağırıyor."}, 1000, 1},
        {{L"\nSebinchi: Küçük Ozan, orda hiç de fena değildin ha! Ama hâlâ kat edecek çok yolun var."}, 1000, 1},
        {{L"\nTam o sırada barın kapısı açılır. Koyu renkli peleriniyle tanıdık bir figür, barın karanlık köşesine doğru ilerler."}, 3000, 1},
        {{L"\nBu, daha önce tüccarlar hakkında bilgi veren adam!"}, 1000, 1},
        {{L"\nSebinchi: \"Hmm, yine neyin peşindesin bakalım?\""}, 1000, 1},
        {{L"\nAdam: (Oturur, çantasından bir harita çıkarır.) \"Haydutlarla ilgili bilgi istediğinizi duydum. Şanslısınız, çünkü bu bölgede onların birkaç saklanma yeri var. Ama dikkat edin, bu insanlar tehlikelidir.\""}, 1000, 1},
        {{L"\nSen: \"Bu bilgiyi neden bizimle paylaşıyorsun? Sana ne kazandırıyor?\""}, 1000, 1},
        {{L"\nAdam: (Gülerek) \"Ben sadece bir tüccarım. Bilgi tüccarı. Siz hayatta kalırsanız, belki başka işlerimiz olur. Eğer ölürseniz… bu da bir kayıp sayılmaz.\""}, 1000, 1},
        {{L"\nSebinchi: \"Boş lafı kes. Nerede bu haydutlar?\""}, 1000, 1},
        {{L"\nAdam: \"İşte burada. Eski bir madende saklanıyorlar. Zenginlerden çaldıkları altınları orada saklıyorlar. Eğer altınlarını alabilirseniz, büyük bir darbe vurmuş olursunuz.\""}, 1000, 1},
        {{L"\nSebinchi ile birlikte yola çıktın."}, 1000, 1},
        {{L"\nHava kararmaya başladı ve ormandaki sessizlik giderek artıyor."}, 1000, 1},
        {{L"\nSebinchi önden gidiyor, sen ise haritayı dikkatlice takip ediyorsun."}, 1000, 1},
        {{L"\nSen: \"Bu haydutlar neden zenginleri hedef alıyor? Sadece altın için mi?\""}, 1000, 1},
        {{L"\nSebinchi: \"Hıh, büyük ihtimalle. Ama bu dünyada herkesin bir bahanesi vardır, ozan. Hayatta kalmaya çalışanlar için her şey meşrudur.\""}, 1000, 1},
        {{L"\nOlamaz! Mağaranın girişinde birkaç haydut var!"}, 1000, 1},
        {{L"\nSebinchi: \"Hazır mısın, küçük ozan? Bu sefer savaşa önden sen giriyorsun.\""}, 1000, 1},
        {{L"\nSen: \"Ben mi? Ama—\""}, 1000, 1},
        {{L"\nSebinchi: \"Öğrenmenin en iyi yolu budur. Hadi, hareket et!\""}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues4_part1);

    // İlk savaşı çağırıyoruz

    dialog dialogues4_afterFirstBattle[] = {
        {{L"\nOlamaz! Sayıları çok fazla!"}, 1000, 1},
        {{L"\nSen: \"Sayıları çok fazla. Daha dayanabilir miyiz bilmiyorum…\""}, 1000, 1},
        {{L"\n\"Bu saçma gruptan bıktım artık. Şimdi ne halt ettiklerini görsünler!\""}, 1000, 1},
        {{L"\nHadi, bu işi bitirelim. Sizinle savaşmıyoruz. Haydutlardan kurtulmak istiyoruz.\""}, 1000, 1},
        {{L"\nSebinchi: (Şaşırmış bir ifadeyle) \"Bunlar altınlarımızı çalan çocuklar ama işimize yarayacak gibi görünüyorlar.\""}, 1000, 1},
        {{L"\nSen: \"Tamam. Hadi bunu birlikte yapalım.\""}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues4_afterFirstBattle);

    // İkinci savaşı çağırıyoruz (4 kişilik takım savaşı)

    dialog dialogues4_afterSecondBattle[] = {
        {{L"\nHaydut lideri kaçar! Tüm altınlar size kaldı, ancak büyük bir kısmı zaten gitmiş.\""}, 1000, 1},
        {{L"\nSebinchi: \"Güçlerini beğendim. Ama hâlâ kim olduklarını öğrenmemiz gerekiyor.\""}, 1000, 1},
        {{L"\nBroski: (Bir ağaca yaslanarak) \"Biz… buraya ait değiliz. Bu haydutlar bizi kandırdı. Köyümüzü yeniden inşa etmek için bize yardım edeceklerini söylediler. Ama onların tek yaptığı bizi kullanmaktı.\""}, 1000, 1},
        {{L"\nLyria: \"Küçüktük… her şeyimizi kaybetmiştik. Yangından sadece biz kurtulduk. Haydutlar bizi bulduğunda, onların doğru olanı yaptığını düşündük. Ama her şey bir yalanmış.\""}, 1000, 1},
        {{L"\nSebinchi: \"Ne diyorsun, ozan? Bu çocuklar bize yararlı olur mu?\""}, 1000, 1},
        {{L"\0"},10,1},
    };

    printSequence(dialogues4_afterSecondBattle);

    wchar_t sorgu1[] = {L"Ne yapacaksınız?"};
    wchar_t secenekler1[1][300] = {
        L"Sanırım herkesin ikinci bir şansı hak ettiği bir an vardır.",
    };

    dialogChoice(sorgu1, secenekler1, 1);

    dialog dialoguesEnd[] = {
        {{L"\nSebinchi: \"Öyleyse… hoş geldiniz. Ama unutmayın, bu yol kolay olmayacak.\""}, 1000, 1},
        {{L"\nHana döndünüz."}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialoguesEnd);
}
