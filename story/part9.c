#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part9.h"

void part9() {

    dialog dialogues9_part1[] = {
        {{L"\nSon hazırlıkları tamamladınız."}, 1000, 1},
        {{L"\nSebinchi: \"Bu işi bitirme zamanı. Hadi, artık yola çıkalım.\""}, 1000, 1},
        {{L"\nKael’i ile buluşma noktasına doğru yola çıktınız."}, 1000, 1},
        {{L"\nBuluşma noktasına vardınız."}, 1000, 1},
        {{L"\nKaranlık bir figür…"}, 1000, 1},
        {{L"\nSelia…"}, 1000, 1},
        {{L"\nİnce bir asa tutmakta. Gözleri hüzün ve kararlılıkla parlıyor."}, 1000, 1},
        {{L"\nSelia: \"Kael seni bekliyor. Ama onu yenebileceğini mi sanıyorsun? Lir’i elinden almak için yapamayacağı şey yok.\""}, 1000, 1},
        {{L"\nSen: \"Bu onun sorunu. Ben lir’i koruyacağım. Ne olursa olsun.\""}, 1000, 1},
        {{L"\nSelia: \"Ahhhahahah… Hala aynı inatla konuşuyorsun. Ama bil ki Kael yalnız değil. Sen gittiğinden beri çok şey oldu.\""}, 1000, 1},
        {{L"\nKaranlık… çok karanlık şeyler… Eğer şimdi vazgeçmezsen, bu sadece senin değil, herkesin sonu olabilir.\""}, 1000, 1},
        {{L"\nSebinchi: (Hiddetle) \"Bu çok bilmiş de kim oluyor? Ağzına bir patlatayım da—\""}, 1000, 1},
        {{L"\nSen: \"Sorun yok, Sebinchi. Kendisi küçük kız kardeşim olur…\""}, 1000, 1},
        {{L"\nSebinchi: ....!\""}, 1000, 1},
        {{L"\nSelia’yı takip ediyorsunuz."}, 1000, 1},
        {{L"\nKael’i gördünüz, bir kayanın üstünde."}, 1000, 1},
        {{L"\nArkasında kıvrılarak yükselen karanlık bir enerji var."}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues9_part1);

    // İlk savaşı çağırıyoruz

    dialog dialogues9_afterFirstBattle[] = {
        {{L"\nKael: \"Sonunda geldiniz. Küçük kardeşim, lir’i de getirmiş. Tam beklediğim gibi.\""}, 1000, 1},
        {{L"\nSen: \"Kael, bu işin sonu geldi. Lir’i asla sana vermeyeceğim.\""}, 1000, 1},
        {{L"\nKael: \"Hala anlamıyorsun değil mi. Bu lir’in gücü benim elimde olmalı. Onunla dünyayı değiştirebilirim. Senin gibiler bu gücü hak etmiyor.\""}, 1000, 1},
        {{L"\nSelia: \"Kael, dur. Bu kadar ileri gitmek zorunda değilsin. Bu güç, sadece yok ediş getirir.\""}, 1000, 1},
        {{L"\nKael: \"Selia, senin bu zayıflığını daha ne kadar izleyeceğim? Beni mi durduracaksın? Küçük kardeşimizin yanında mı yer alacaksın?\""}, 1000, 1},
        {{L"\nSelia: ...."}, 3000, 1},
        {{L"\nSAVAŞ BAŞLAR."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues9_afterFirstBattle);

    // Kael ile büyük savaşı çağırıyoruz

    dialog dialogues9_afterSecondBattle[] = {
        {{L"\nKael, gözlerini kapattı. BUM! HAYIR HAYIR HAYIR HAYIRRRRR!!!!!"}, 1000, 1},
        {{L"\nBroski, Lyria ve Sebinchi yerde yatıyorlar…"}, 1000, 1},
        {{L"\nSelia: \"Kael, yeter! Kendini kaybediyorsun!\""}, 1000, 1},
        {{L"\nKael: \"Ben bu dünyayı yeniden yaratacağım. Ve bu güçle her şeyi kontrol edeceğim!\""}, 1000, 1},
        {{L"\nSelia bize katılır ve savaş başlar."}, 3000, 1},
        {{L"\nKael’i yenersiniz."}, 1000, 1},
        {{L"\nKael: (Titreyen bir sesle) \"Bard… kazandın… ama bunun bedelini ödeyeceksin. Lir… sadece bir araç… ama… senin elinde… gerçekten… bir mucizeye dönüşebilir…\""}, 1000, 1},
        {{L"\nSen: \"Kael, bunu yapmak zorunda değildin… Bu kadar ileri gitmek zorunda değildin!\""}, 1000, 1},
        {{L"\nKael: \"Ben… doğruyu yaptım… ama sen daha iyisini yap… kardeşim…\""}, 1000, 1},
        {{L"\nKael patladı!"}, 3000, 1},
        {{L"\nÇabuk! Hemen arkadaşlarının yanına git!\""}, 1000, 1},
        {{L"\nBroski ve Lyria yaralanmış ama hayatta."}, 1000, 1},
        {{L"\nAma Sebinchi…\""}, 1000, 1},
        {{L"\nSen: \"Sebenchi! Hadi, uyan! Beni duyabiliyor musun?\""}, 1000, 1},
        {{L"\nBroski: \"Sebenchi… hayır… bu gerçek olamaz…\""}, 1000, 1},
        {{L"\nLyria: (Gözyaşları içinde) \"Onun gibi biri… böyle… gidemez… O bizim liderimizdi!\""}, 1000, 1},
        {{L"\nSen: \"Hayır… hayır! Bu gerçek olamaz! Sebenchi, beni yalnız bırakma!\""}, 1000, 1},
        {{L"\nLir’in telleri parlıyor! Son bir güçle şarkı çalmaya başlarsın."}, 3000, 1},
        {{L"\nSen: (Umutsuzca) \"Lütfen… bir kez daha. Lütfen bana geri dön… Seni kaybedemem!\""}, 1000, 1},
        {{L"\nSebinchi parlıyor mu yoksa!"}, 1000, 1},
        {{L"\nSebinchi: \"Ozan… sen gerçekten… bir mucize yarattın…\""}, 1000, 1},
        {{L"\nSen: \"Seni kaybedemezdim. Bunu asla yapamazdım.\""}, 1000, 1},
        {{L"\nLir’in ışığı söndü, teller sessizleşti. Ahşap gövdesinde hafif çatlaklar beliriyor. Artık sadece sıradan bir enstrüman olduğunu hissediyorsun."}, 1000, 1},
        {{L"\nSebinchi: \"Lir’in gücü… hepsi bitti, değil mi?\""}, 1000, 1},
        {{L"\nSen: \"Evet… ama doğru olanı yaptık. Seni kurtardık.\""}, 1000, 1},
        {{L"\nSebinchi: \"Ozan… bana bir iyilik yap. Artık onu… kendi yükün olarak görme. O, senin mucizen.\""}, 1000, 1},
        {{L"\nZafer sizin!\""}, 3000, 1},
        {{L"\nBroski: \"Hadi, hana dönelim. Belki hâlâ sağlam bir masa bulabiliriz.\""}, 1000, 1},
        {{L"\nHancı: \"Ah umarım özel Karadion şarabıma dokunmamışlardır!\""}, 1000, 1},
        {{L"\nLyria: \"Bu, büyük bir kutlamayı hak ediyor.\""}, 1000, 1},
        {{L"\nSebinchi: \"Ama küçük ozan, bu sefer içkiler senden olacak.\""}, 1000, 1},
        {{L"\nSen: \"Ne kazandıysak sizin için harcamaya hazırım.\""}, 1000, 1},
        {{L"\n…. SON."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues9_afterSecondBattle);
}
