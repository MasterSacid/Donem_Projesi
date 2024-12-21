#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/console.h"
#include "narrative.h"
#include "part7.h"

void part7() {

    dialog dialogues7_part1[] = {
        {{L"\nFinn: \"Onları yalnız bırakamayız! Sebinchi bir şekilde hayatta kalır, ama ya Broski ve Lyria? Onlar bu kadar şanslı olmayabilir.\""}, 1000, 1},
        {{L"\nHancı: \"Sakin ol, Finn. Hızlı ama dikkatli hareket etmeliyiz. Bu işler aceleye gelmez. Planı takip edersek her şey yolunda gider.\""}, 1000, 1},
        {{L"\nHazırlanıp dışarı çıktınız."}, 1000, 1},
        {{L"\nAdam: \"Yine bir karmaşanın içinde olduğunuzu görüyorum. Sebinchi ve diğerleri için mi endişeleniyorsunuz?\""}, 1000, 1},
        {{L"\nSen: \"Sen de her şeyi nereden biliyorsun! Bir planın varsa çabuk söyle.\""}, 1000, 1},
        {{L"\nAdam: \"Sebenchi’nin geçmişinden gelen bir klan var. Bir zamanlar ailesi gibi gördüğü bir topluluk. Eğer onlara ulaşabilirseniz, yardım alabilirsiniz. Ancak bu kolay olmayacak.\""}, 1000, 1},
        {{L"\nFinn: \"Peki, neden kolay olmayacak?\""}, 1000, 1},
        {{L"\nAdam: \"Bu insanlar, Sebinchi’yi hâlâ seviyor olabilir ama misafirlere dostane davranmazlar.\""}, 1000, 1},
        {{L"\nSen: \"Ne olduğunun bir önemi yok. Onları nasıl bulabiliriz?\""}, 1000, 1},
        {{L"\nAdam: \"Ormanın derinliklerinde bir yer. Taş bir kapı göreceksiniz. Ama unutmayın, bu insanlar Sebinchi’yi terk ettiğiniz gibi kolayca affetmez.\""}, 1000, 1},
        {{L"\nAdam’ın verdiği haritayı takip ederek ormanın derinliklerine ilerlersiniz."}, 1000, 1},
        {{L"\nSen: \"Bu klan hakkında herhangi bir bilgin var mı?\""}, 1000, 1},
        {{L"\nHancı: \"Bilmiyorum. Sebinchi kendisinden pek bahsetmez.\""}, 1000, 1},
        {{L"\nKapıya vardınız."}, 1000, 1},
        {{L"\nKlan Üyesi: \"Sebenchi’nin adını kullanarak buraya geldiniz. Bu bir cesaret, ama aynı zamanda bir cüret!\""}, 1000, 1},
        {{L"\nSen: \"Bekleyin! Biz Sebinchi’yi kurtar...\""}, 1000, 1},
        {{L"\nHer şey karanlığa gömüldü."}, 3000, 1},
        {{L"\nGözlerini açtın, sımsıcak kumların üzerindesin."}, 1000, 1},
        {{L"\nEtrafında yüksek bir arena duvarı var. Yukarıda, Finn ve Hancı bir direğe kazığa bağlı. İkisinin de yüzleri korkudan bembeyaz!\""}, 1000, 1},
        {{L"\nBir savaşçı arenaya girdi ve sana doğru bakıyor!"}, 1000, 1},
        {{L"\nKlan Lideri: \"Sebenchi’nin adını andınız. Onun adı kolay kolay anılmaz. Adını hak etmek istiyorsanız, yeteneklerinizi gösterin. Hayatta kalırsanız konuşuruz.\""}, 1000, 1},
        {{L"\nSen: \"Biz buraya savaşmaya gel...\""}, 1000, 1},
        {{L"\nKlan Lideri: \"Çok konuşma ve savaş!\""}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues7_part1);

    // Arena savaşını çağırıyoruz

    dialog dialogues7_afterArenaBattle[] = {
        {{L"\nKazandık!"}, 1000, 1},
        {{L"\nEldrion: \"Durun! Bu kadar yeter. Sebinchi’nin adını anan biri, onun ismini onurlandırmayı başardı. Onları getirin!\""}, 1000, 1},
        {{L"\nArenadan çıkarılıp büyük bir salona götürülürsünüz."}, 1000, 1},
        {{L"\nEldrion: \"Evet. Sebinchi’yi nereden tanıyorsunuz ve onunla işiniz nedir? Neden bizden ayrıldığını biliyor musunuz?\""}, 1000, 1},
        {{L"\nSen: \"Hayır, ama şu anda bu önemli değil. Onun hayatı tehlikede!\""}, 1000, 1},
        {{L"\nEldrion: \"Sizinle geleceğiz. Ama önce bilmeniz gereken bir şey var.\""}, 1000, 1},
        {{L"\nEldrion: \"Sebenchi bir savaşçıydı. Genç, ateşli ve korkusuz. Ama ben barışı seçtim. Bu topraklar için çok savaştım. Savaş sadece ölüm ve kayıplar getirir. Halkımı korumak için zenginlerle barış yaptım. Sebinchi bunu kabul etmedi.\""}, 1000, 1},
        {{L"\nFinn: \"O zaman Sebinchi sizi neden terk etti?\""}, 1000, 1},
        {{L"\nEldrion: \"Çünkü o, gençliğimi hatırlatıyor bana. Adalet arayışı, cesareti… Ama onun yöntemi, benimkinden farklı. Yine de Sebinchi bizim bir parçamız. Onu kurtarmak için elimizden geleni yapacağız.\""}, 1000, 1},
        {{L"\nKlan üyeleriyle birlikte Sebinchi’nin tutulduğu haydut kampına ilerliyorsunuz."}, 3000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues7_afterArenaBattle);

    // Haydut kampı savaşını çağırıyoruz

    dialog dialogues7_afterCampBattle[] = {
        {{L"\nSebenchi: \"Bu kadar zaman geçti ve sonunda geldiniz. Daha hızlı olamaz mıydınız?\""}, 1000, 1},
        {{L"\nSen: \"Ama geldik. Seni yalnız bırakmayacağımızı biliyordun.\""}, 1000, 1},
        {{L"\nSebenchi: (Alaycı bir şekilde) \"Belki de seni hafife almışım. Şimdi şu haydutları bitirelim.\""}, 1000, 1},
        {{L"\nBroski ve Lyria: \"Lütfen bizi de çözer misiniz! Bizi de unutmadığınız için teşekkür ederiz!\""}, 1000, 1},
        {{L"\nHaydut lideri kaçtı, ancak kamp tamamen temizlendi!\""}, 1000, 1},
        {{L"\nEldrion, Sebinchi’ye yaklaşıyor: \"Bu hâlâ senin evin, Sebinchi. Ama seçim senin.\""}, 1000, 1},
        {{L"\nSebenchi: ..."}, 1000, 1},
        {{L"\nSebenchi: \"Hadi küçük ozan, hana geri dönelim.\""}, 1000, 1},
        {{L"\nSebenchi çok sessiz..."}, 3000, 1},
        {{L"\nKampa geri döndünüz."}, 1000, 1},
        {{L"\0"}, 10, 1},
    };

    printSequence(dialogues7_afterCampBattle);
}
