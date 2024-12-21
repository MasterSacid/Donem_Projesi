#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part8.h"

void part8() {

    dialog dialogues8_part1[] = {
        {{L"\nHanın loş ışıkları altında herkes sessizce oturuyor."}, 1000, 1},
        {{L"\nMasada gergin bir hava var."}, 1000, 1},
        {{L"\nSebinchi ise kılıcını temizlerken hiçbir şey olmamış gibi davranıyor."}, 1000, 1},
        {{L"\nSessizliği daha fazla kaldıramıyorsun."}, 1000, 1},
        {{L"\nSen: \"Bu iş gerçekten bitti mi? Haydutlar konusunda hâlâ bir şeyler yapılması gerektiğini düşünmüyor musunuz?\""}, 1000, 1},
        {{L"\nBroski: (Başını kaldırır) \"Haklısın. Tamamen bitmedi. Mağarada bulduğumuz belgeler… Her şeyin başındaki liderin yerini işaret ediyor.\""}, 1000, 1},
        {{L"\nLyria: (Ciddi bir ifadeyle) \"Evet. Haydutların en üst seviyesindeki lider ve kalan yüksek rütbeliler… Hepsi burada.\""}, 1000, 1},
        {{L"\nSebinchi: (Kısık bir gülüşle) \"Pekâlâ. Bu işi kökten bitirmenin zamanı geldi. Ama bu sefer, küçük ozan, bizimle geliyorsun. Yaptığın hataları telafi etmek için bir şans bu.\""}, 1000, 1},
        {{L"\nSen: \"Yani… gerçekten mi? Yanınıza alacaksınız?\""}, 1000, 1},
        {{L"\nSebinchi: \"Hala güvenimi geri kazandığını söyleyemem. Ama eğer işler sarpa sararsa, birinin dikkat dağıtması gerekebilir.\""}, 1000, 1},
        {{L"\nHançer gibi soğuk bir gece havasında yola çıkarsınız."}, 3000, 1},
        {{L"\nLyria: \"Haydut lideri… O kadar uzun zamandır buradalar ki bu sistemi kurmuş ve diğerlerini de ona bağlamış. Bu iş zenginleri soymakla başlamış ama sonra bir güç oyunu olmuş.\""}, 1000, 1},
        {{L"\nBroski: \"Ama onu yenmek her şeyi bitirecek. Haydutlar bir arada kalamaz, sistem çöker.\""}, 1000, 1},
        {{L"\nBir süre sonra…"}, 1000, 1},
        {{L"\nBir kale var! İçeri girdiniz."}, 1000, 1},
        {{L"\nKolay savaşlar oluyor."}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues8_part1);

    // Liderin bulunduğu salona ilerlerken savaşı çağırıyoruz

    dialog dialogues8_part2[] = {
        {{L"\nLiderin olduğu salona ulaşıyorsunuz."}, 1000, 1},
        {{L"\nLyria: \"Sen… Bu sistemi kuran kişi sensin! Köyümüzü yağmaladınız, hayallerimizi yıktınız! Şimdi bunun bedelini ödeyeceksin!\""}, 1000, 1},
        {{L"\nHaydut Lideri: (Alaycı bir şekilde) \"Köyünüz mü? Hangi köyden bahsediyorsun, küçük kız? Ben sizi tanımıyorum bile. Sistem böyle işler. Alt tabakalar bir şekilde ezilir. Bu benim suçum değil.\""}, 1000, 1},
        {{L"\nBroski: \"Sistemi kuran sensin! Tüm bu çöküşün sorumlusu sensin!\""}, 1000, 1},
        {{L"\nHaydut Lideri: \"Ben mi? Hayır. Ben sadece oyunu kurallarına göre oynadım. Zenginlerden çaldım, ama herkes için değil… Siz… siz ise sadece bir araçtınız.\""}, 1000, 1},
        {{L"\nLyria: \"Yalan söylüyorsun! Bizi kullandın, umutlarımızla oynadın!\""}, 1000, 1},
        {{L"\nHaydut Lideri: \"Kullandıysam ne olmuş? Güç, zayıfları ezmek içindir. Eğer bunu anlamıyorsanız, daha fazla konuşacak bir şey yok.\""}, 3000, 1},
        {{L"\nSON SAVAŞ BAŞLAR."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues8_part2);

    // Son savaşı çağırıyoruz

    dialog dialogues8_postBattle[] = {
        {{L"\nSonunda, haydut liderini yenmeyi başardınız!"}, 1000, 1},
        {{L"\nSistem çöktü ve haydutlar tamamen dağıldı!"}, 1000, 1},
        {{L"\nHana doğru geri yürüyorsunuz."}, 1000, 1},
        {{L"\nBroski: \"Artık her şey bitti! Bu gece büyük bir kutlama yapmalıyız. Biraz eğlenmeyi hak ettik.\""}, 1000, 1},
        {{L"\nFinn: \"Evet! Hancı bize harika bir ziyafet hazırlayabilir!\""}, 1000, 1},
        {{L"\nSen: \"Finn sen de nereden çıktın!\""}, 1000, 1},
        {{L"\nHana varılır."}, 1000, 1},
        {{L"\nOlamaz! Ne olmuş öyle!"}, 1000, 1},
        {{L"\nHer yer darmadağınık, masalar devrilmiş, şişeler kırılmış."}, 1000, 1},
        {{L"\nTüm han talan edilmiş!"}, 1000, 1},
        {{L"\nFinn: \"Burada bir kağıt var.\""}, 1000, 1},
        {{L"\nOzan, seni bulmak uzun sürdü. Ama sonunda seni yakaladım. Adamların artık benim elimde. Onu geri almak istiyorsan, cesaretini göster ve düelloya gel. Buluşma yeri ve zamanı yazılı. Kardeşlerin adına… Kael."}, 1000, 1},
        {{L"\nLyria: \"Bu da ne demek? Olamaz Hancı nerede!\""}, 1000, 1},
        {{L"\nGarson saklandığı yerden çıktı!"}, 1000, 1},
        {{L"\nGarson: \"Hancı ve Adamı aldılar.\""}, 1000, 1},
        {{L"\nBroski: \"Kim bu Kael? Ödül avcısı falan mı ?\""}, 1000, 1},
        {{L"\nSen: (Lirine bakarak) \"Bu uzun bir hikâye… Ama onları geri almamız gerekiyor. Ve bu, benim sorumluluğum.\""}, 1000, 1},
        {{L"\nSebinchi: \"Bu kez senden kaçmayacağım, ozan. Bunu çözmek için ne gerekiyorsa yapacağız.\""}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues8_postBattle);
}
