#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part5.h"

void part5() {

    dialog dialogues5_part1[] = {
        {{L"\nSebinchi: \"Bir içki daha!\""}, 1000, 1},
        {{L"\nLyria: \"Bu haydut çeteleri… sadece başlangıç. Daha büyük grupları da var. Ve onların, zenginlerden çaldıkları altınlarla güçlendiklerini biliyoruz.\""}, 1000, 1},
        {{L"\nBroski: \"O yüzden harekete geçmemiz lazım. Onların liderlerini yok edersek, diğer gruplar dağılıp gider. Köyümüzü yeniden inşa etmek için başka şansımız yok.\""}, 1000, 1},
        {{L"\nSebinchi: (Gülerek) \"Ah, ne kadar da idealist bir düşünce. Ama altınlarınızı geri almak istiyorsanız, benimle çalışmanız gerekiyor. Ve tabii ki küçük ozanımız da bizimle gelecek.\""}, 1000, 1},
        {{L"\nSen: \"Sebinchi, bu bizimle ne ilgisi var? Neden bu kadar heveslisin?\""}, 1000, 1},
        {{L"\nSebinchi: (Sert bir bakışla) \"Altın. Daha fazla altın. Ve tabii ki eğlence.\""}, 1000, 1},
        {{L"\nSebinchi: \"Ama bunu sorgulama hakkın yok. Hadi, hareket et.\""}, 1000, 1},
        {{L"\nBüyük bir haydut çetesinin kampına gitmek için yola çıktınız."}, 3000, 1},
        {{L"\nSebinchi size tip tip bakıyor. Nihayet sıkıcı sessizliği bozar ve:"}, 1000, 1},
        {{L"\nSebinchi: \"Şimdi bana doğruyu söyle, küçük ozan. Sen neden buradasın? Bu şehre, bu köye neden geldin?\""}, 1000, 1},

        {{L"\0"}, 10, 1},

    };

    printSequence(dialogues5_part1);

    wchar_t sorgu1[] = {L"Sebinchi’ye ne söyleyeceksin?"};
    wchar_t secenekler1[1][300] = {
        L"Sadece… bir yerden bir yere gidiyorum. Gezgin bir ozanım, bu kadar.",
    };

    dialogChoice(sorgu1, secenekler1, 1);

    dialog dialogues5_part2[] = {
        {{L"\nSebinchi: (Gülerek) \"Pek inandırıcı değil. Ama neyse, bu senin sırların. Ancak bir gün, o sırlar seni ele verecek.\""}, 1000, 1},
        {{L"\nBroski: \"Sebinchi, ona biraz nefes aldır. Haydutları alt etmek için birbirimize ihtiyacımız var, sorgulamaya değil.\""}, 1000, 1},
        {{L"\nSebinchi: \"Sorgulamak, her zaman işe yarar, Broski. Özellikle biri yalan söylüyorsa.\""}, 1000, 1},
        {{L"\nHaydut Kampı."}, 1000, 1},
        {{L"\nSebinchi: \"Plan basit. Onları şaşırtacağız ve hızlıca alt edeceğiz. Ama dikkatli olun. Burası sıradan bir kamp değil.\""}, 1000, 1},
        {{L"\nSAVAŞ BAŞLAR."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues5_part2);

    // İlk savaşı çağırıyoruz

    dialog dialogues5_afterFirstBattle[] = {
        {{L"\nSAVAŞ BİTER. Haydutları alt ettiniz! Artık hana dönebilirsiniz!"}, 1000, 1},
        {{L"\nHey durun orda!"}, 1000, 1},
        {{L"\nNihayet seni buldum. Lir’i korumak için çok çabalıyorsun, ama bu çaba boşuna. Teslim ol ve hayatını kurtar."}, 1000, 1},
        {{L"\nSebinchi: \"Ne oluyor burada? Küçük ozan, bu kim?\""}, 1000, 1},
        {{L"\nSen: \"Ben… bilmiyorum.\""}, 1000, 1},
        {{L"\nBroski: \"Sanırım, bu açıklamayı sonra yaparsın. Şimdi savaşa odaklanalım!\""}, 1000, 1},
        {{L"\nBOSS SAVAŞI BAŞLAR."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues5_afterFirstBattle);

    // Boss savaşı çağırıyoruz

    dialog dialogues5_afterBossBattle[] = {
        {{L"\nÖdül Avcısı: (Kan kaybederken) \"Seni bulacaklar… lir asla güvende olmayacak…\""}, 1000, 1},
        {{L"\nSebinchi, kılıcını yerine koyar ve sert bir şekilde sana döner."}, 1000, 1},
        {{L"\nSebinchi: \"Bu neydi? Bana hemen açıklama yap, ozan. Şimdi bu işi çözmezsen, ben çözerim.\""}, 1000, 1},
        {{L"\nBroski ve Lyria da sana şüpheyle bakıyor."}, 1000, 1},
        {{L"\nSebinchi: \"Bu kadar zaman yalan mı söyledin? Kim olduğunu ve neden buraya geldiğini anlat. Yoksa seni şuracıkta…\""}, 1000, 1},
        {{L"\nSen: \"Bu lir… benim için sıradan bir enstrüman değil. Büyükbabamdan bana miras kaldı. Ancak ailem… bunu elimden almak istiyor."}, 1000, 1},
        {{L"\nKardeşlerim üstüme ödül kondurdu. Beni avlıyorlar, çünkü lirin taşıdığı güç onların eline geçerse, neler yapabileceklerini hayal bile edemezsiniz."}, 1000, 1},
        {{L"\nİşte o yüzden sürekli şehir değiştiriyorum.\""}, 1000, 1},
        {{L"\nLyria: \"Bunu neden daha önce söylemedin?\""}, 1000, 1},
        {{L"\nSen: \"Çünkü kimseye güvenemem. Güvenmek, geçmişte beni hep yarı yolda bıraktı.\""}, 1000, 1},
        {{L"\nSebinchi: \"Peki, bu bizi ilgilendiriyor mu? Hayır. Ama senin sırların bizi tehlikeye atıyorsa, bu başka bir mesele. Hadi, hana dönelim. Bu konuşma burada bitmedi.\""}, 1000, 1},
        {{L"\nYolda, herkes sessiz…" }, 3000, 1},
        {{L"\nHana başarıyla döndünüz…\""}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues5_afterBossBattle);
}
