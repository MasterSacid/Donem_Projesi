#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/console.h"
#include <windows.h>
#include "narrative.h"
#include "eventhandler.h"

extern int MISSION_COUNTER;
extern message GAME_MESSAGES[];
extern int GAME_MESSAGE_COUNTER;


void dialoguePerson0() {
    if (MISSION_COUNTER == 0) {
        //Barmen
         message barmen1 = {L"\nBarmen: Daha ne kadar oyalanacaksın, ozan? Burada fazladan oturmanın bir maliyeti olur, unutma."};
         message barmen2 = {L"\nBir içki daha alabilir miyim ?.\n"};
         message barmen3 = {L"\nBarmen: Hahah, paranın olmadığını unuttun galiba."};
         message barmen4 = {L"\n\0"};

        message barmen[] = {barmen4, barmen3, barmen2, barmen1};

        for (int i = 3; i >= 0; --i) {
            sendToRightSection(barmen[i]);
        }
    }
    if (MISSION_COUNTER == 1) {
        message hanci1 = {L"Hancı: (Gülümseyerek) Saklanma numaralarından sıkıldın mı ozan? Şimdi buraya geldiysen, bir içki söyle ve kalabalıkla kaynaş. Yoksa burada uzun süre barınamazsın."};
        message hanci2 = {L"Sen: Kalabalıkla kaynaşmak mı? Peşimdeki gardiyandan zar zor kurtuldum. Şimdi bir de burada mı sorun yaşayacağım?"};
        message hanci3 = {L"Hancı: (Gülümser) Sorun değil, fırsat yarat burası. Kiminle konuşacağını seç; belki bir sır öğrenir, belki bir iş kaparsın."};
        message hanci4 = {L"\0"};
        message hanci[10] = {hanci4, hanci3, hanci2, hanci1};
        for (int i = 0; i < 3; ++i) {
            sendToRightSection(hanci[i]);
        }
    }
    if (MISSION_COUNTER == 2) {
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
    if (MISSION_COUNTER == 3) {
        message hanci1 = {L"Hancı: (Tezgâhın arkasında içki doldururken başını kaldırır ve size bakar.) Demek geri döndünüz. Biraz daha uzun kalacağınızı düşünmüştüm. Elde ettiğiniz şeylere değdi mi bari?"};
        message hanci2 = {L"Sen: Zaman gösterecek. Ama bu şehirde elde ettiğin her şeyin bedeli olduğunu anladım."};
        message hanci3 = {L"Hancı: (Kısık bir kahkaha atar) Ah, ozan. Burada herkes bir bedel öder. Peki, sıradaki adım nedir? Daha fazla altın mı, yoksa biraz huzur mu?"};
        message hanci4 = {L"\0"};
        message hanci[10] = {hanci4, hanci3, hanci2, hanci1};
        for (int i = 0; i < 3; ++i) {
            sendToRightSection(hanci[i]);
        }


    }
    if (MISSION_COUNTER == 4) {
        message sebinchi1 = {L"(Sebinchi, her zamanki gibi köşedeki masasında oturmuş, kılıcını temizliyor. Seni sert bir bakışla yanına çağırır.)"};
        message sebinchi2 = {L"Sebinchi: Küçük ozan, bu lirinle ilgili söylediklerin doğruysa, hepimizi büyük bir tehlikeye soktun. Bu yola birlikte çıktık, ama hâlâ tam olarak nerede durduğunu bilmiyorum."};
        message sebinchi3 = {L"Sen: Bunu planlamadım, Sebinchi. Liri korumak için başka çarem yoktu. Ama bu yol sadece benim sorumluluğum değil mi?"};
        message sebinchi4 = {L"Sebinchi: (Hafif bir kahkaha atar) Bu noktadan sonra sorumluluklarımız ortak. Ama lirin yüzünden bir kez daha tehlikeye girersek, bu sefer daha fazla sorgu sual olmayacak."};
        message sebinchi5 = {L"\0"};
        message sebinchi[10] = {sebinchi5, sebinchi4, sebinchi3, sebinchi2, sebinchi1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(sebinchi[i]);
        }


    }
    if (MISSION_COUNTER == 5 ) {
        message hanci1 = {L"(Hancı, tezgâhın arkasında, bir şeyler düşünürken sana döner.)"};
        message hanci2 = {L"Hancı: Sana söyledim, ozan. Bu işler hep böyle biter. Büyük sırlar, büyük düşmanları çeker. Ama artık kaçış yok. Bu sefer savaşmak zorundasın."};
        message hanci3 = {L"Sen: Savaşmak mı? Sebinchi ve diğerleri hâlâ dışarıda. Onlara yardım etmeden burada oturamam."};
        message hanci4 = {L"Hancı: (Başını sallayarak) O zaman bir plan yap. Ama unutma, plansız bir kahraman sadece ölmek için yola çıkar."};
        message hanci5 = {L"\0"};
        message hanci[10] = {hanci5, hanci4, hanci3, hanci2, hanci1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(hanci[i]);
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
        message sebinchi1 = {L"(Sebinchi, barın köşesinde, masaya eğilmiş kılıcını yavaşça cilalıyor.)"};
        message sebinchi2 = {L"Sebinchi: Şimdi ne yapmayı planlıyorsun, ozan? Şehirden kaçarken ki cesaretini burada da gösterecek misin?"};
        message sebinchi3 = {L"Sen: Pek seçeneğim yok gibi görünüyor. Ama şunu sorayım: Şehirde senin gibi güçlü biri neden bir handa zaman harcar?"};
        message sebinchi4 = {L"Sebinchi: (Kısık bir kahkaha atar) Güç, yalnızca bir araç. Burası ise bilmek istediğin her şeyin başlangıç noktası. Sana bir sır vereyim, ozan: Fırsatlar, konuştuğun insanlarda gizlidir."};
        message sebinchi5 = {L"\0"};
        message sebinchi[10] = {sebinchi5, sebinchi4, sebinchi3, sebinchi2, sebinchi1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(sebinchi[i]);
        }

    }
    if (MISSION_COUNTER == 2) {
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
    if (MISSION_COUNTER == 3) {
        message sebinchi1 = {L"(Sebinchi, köşedeki masasında oturmuş, kılıcını masaya bırakmış ve bir içki yudumluyor. Seni görünce hafifçe gülümser.)"};
        message sebinchi2 = {L"Sebinchi: Güzel bir iş çıkardın, küçük ozan. Ama şunu unutma: zaferin rehavetine kapılırsan, bir sonraki savaşı kaybedersin."};
        message sebinchi3 = {L"Sen: Peki ya sen, Sebinchi? Bu kadar tehlikenin arasında hâlâ neden burada kalıyorsun?"};
        message sebinchi4 = {L"Sebinchi: (Omuz silkerek) Bazı savaşlar, savaşmaktan daha fazlasını gerektirir. Burada kalmamın nedeni bu. Ama endişelenme, seninle olduğum sürece bu savaşı birlikte vereceğiz."};
        message sebinchi5 = {L"\0"};
        message sebinchi[10] = {sebinchi5, sebinchi4, sebinchi3, sebinchi2, sebinchi1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(sebinchi[i]);
        }


    }
    if (MISSION_COUNTER == 4) {
        message broski1 = {L"(Broski, bir masanın kenarına yaslanmış, boş bir içki kadehiyle oynuyor. Seni görünce bakışlarını sertleştirir.)"};
        message broski2 = {L"Broski: Ozan, bu liri korumak için neden bu kadar ileri gidiyorsun? Bu sadece bir aile yadigârı mı? Yoksa başka bir şey mi saklıyorsun?"};
        message broski3 = {L"Sen: Bu lirin gücünün farkındayım, Broski. Ama bu gücün yanlış ellerde olmasının sonuçlarını da biliyorum."};
        message broski4 = {L"Broski: (Derin bir nefes alır) Pekâlâ. Ama bunu söylemek yetmez. Eğer bu lirin yüzünden hayatlarımız tehlikeye girecekse, bu savaş sadece senin değil, bizim de sorunumuz olacak."};
        message broski5 = {L"\0"};
        message broski[10] = {broski5, broski4, broski3, broski2, broski1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(broski[i]);
        }


    }
    if (MISSION_COUNTER == 5 ) {
        message finn1 = {L"(Finn, elinde bir kadeh tutarak sana yaklaşır. Yüzünde korku ve kararlılık bir arada okunur.)"};
        message finn2 = {L"Finn: Ozan! Sebinchi, Broski ve Lyria’nın başı dertte. Hemen bir şeyler yapmalıyız!"};
        message finn3 = {L"Sen: Finn, sakin ol. Ne olduğunu tam olarak biliyor musun?"};
        message finn4 = {L"Finn: Bilmiyorum, ama onları tuzağa düşürdüler. Haydutlar çok fazlaydı ve silahlıydılar. Onları kurtarmak için bir şeyler yapmamız lazım!"};
        message finn5 = {L"\0"};
        message finn[10] = {finn5, finn4, finn3, finn2, finn1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(finn[i]);
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
    if (MISSION_COUNTER==1) {
        message finn1 = {L"(Finn, küçük bir masanın yanında, heyecanla etrafı izliyor ve seni görünce gözleri parlıyor.)"};
        message finn2 = {L"Finn: Sen ozan mısın? Gerçekten mi? Bana bir şarkı söyleyecek misin?"};
        message finn3 = {L"Sen: Belki bir gün. Ama şimdilik dinlenmem gerekiyor."};
        message finn4 = {L"Finn: (Yaklaşır ve fısıldar) Bir keresinde annem bana bu barda bir hazinenin saklandığını söyledi. Gerçekten bir şeyler biliyor musun? Annem hep abartır ama belki sen biliyorsundur."};
        message finn5 = {L"\0"};
        message finn[10] = {finn5, finn4, finn3, finn2, finn1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(finn[i]);
        }
    }
    if (MISSION_COUNTER == 2) {
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
    if (MISSION_COUNTER == 3) {
        message broski1 = {L"(Broski, barın bir köşesinde oturmuş, önündeki içkiyi karıştırıyor. Seni görünce el işaretiyle yanına çağırır.)"};
        message broski2 = {L"Broski: Ozan, bu işte iyi bir takım olduk, değil mi? Ama hâlâ kendimi sorguluyorum. Biz, bu dünyada bir fark yaratabilir miyiz?"};
        message broski3 = {L"Sen: Bir fark yaratmak için bir yerden başlamak gerekiyor. Sen neden bu yolda yürüyorsun, Broski?"};
        message broski4 = {L"Broski: (Başını önüne eğer) Bir şeyleri düzeltmek için. Köyümüze ne olduğunu gördün. Artık sadece hayatta kalmak değil, daha fazlasını yapmak istiyorum."};
        message broski5 = {L"\0"};
        message broski[10] = {broski5, broski4, broski3, broski2, broski1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(broski[i]);
        }


    }
    if (MISSION_COUNTER == 4) {
        message lyria1 = {L"(Lyria, masanın başında oturmuş, sessizce bir harita üzerine notlar alıyor. Seni görünce kalemini bırakır ve gözlerini sana diker.)"};
        message lyria2 = {L"Lyria: Ozan, dürüst ol. Bu kadar güçlü bir şey neden senin gibi bir ozanın ellerinde? Kardeşlerin seni avlamak istiyorsa, bu sadece senin hikâyen değil, bizim de sorunumuz haline geldi."};
        message lyria3 = {L"Sen: Lyria, bu liri korumaya yemin ettim. Sadece benim için değil, onun başkalarının eline geçmesini önlemek için de."};
        message lyria4 = {L"Lyria: (Bir an duraksar, sonra başını sallar) Umarım bu uğurda neyi feda etmeye hazır olduğunu biliyorsundur. Çünkü bu yol gittikçe daha tehlikeli hale geliyor."};
        message lyria5 = {L"\0"};
        message lyria[10] = {lyria5, lyria4, lyria3, lyria2, lyria1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(lyria[i]);
        }


    }
    if (MISSION_COUNTER == 5 ) {
        message garson1 = {L"Garson: (Sana yaklaşarak) Ozan, onlar olmadan işler daha zor. Ama herkes burada senin ne yapacağını merak ediyor. Bu sefer liderlik sende."};
        message garson2 = {L"\0"};
        message garson[10] = {garson2, garson1};
        for (int i = 0; i < 1; ++i) {
            sendToRightSection(garson[i]);
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
        message musteri1 = {L"Müşteri: Burada yeni yüzler görmek nadirdir. Sadece hayatta kalmaya mı çalışıyorsun, yoksa gerçekten bir maceracı mısın?"};
        message musteri2 = {L"Sen: Şimdilik hayatta kalmak benim için yeterince büyük bir macera."};
        message musteri3 = {L"Müşteri: O zaman dinle, ozan. Bu şehirde kimse hayatta kalmak için yalnızca şansına güvenmez. Eğer bir yol gösterecek birine ihtiyacın varsa, beni bulabilirsin."};
        message musteri4 = {L"\0"};
        message musteri[10] = {musteri4, musteri3, musteri2, musteri1};
        for (int i = 0; i < 3; ++i) {
            sendToRightSection(musteri[i]);
        }


    }
    if (MISSION_COUNTER == 2) {
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
    if (MISSION_COUNTER == 3) {
        message lyria1 = {L"(Lyria, bir masanın başında oturmuş, eski bir parşömeni katlıyor. Seni fark ettiğinde hafifçe başını sallar.)"};
        message lyria2 = {L"Lyria: Hâlâ hayattayız. Bu bile bir mucize. Ama senin lir… onun hakkında bir şeyler var. Bu kadar insanın peşine düşmesi tesadüf olamaz."};
        message lyria3 = {L"Sen: Benim için sadece bir enstrüman, ama insanlar onu farklı bir şey gibi görüyor."};
        message lyria4 = {L"Lyria: (Ciddileşir) Eğer bu lir gerçekten bir güç barındırıyorsa, onu kullanmayı öğrenmelisin. Yoksa hem senin hem de bizim sonumuz olabilir."};
        message lyria5 = {L"\0"};
        message lyria[10] = {lyria5, lyria4, lyria3, lyria2, lyria1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(lyria[i]);
        }


    }
    if (MISSION_COUNTER == 4) {
        message finn1 = {L"(Finn, barın köşesinde, küçük bir kutuyla oynuyor. Seni görünce heyecanla yanına gelir.)"};
        message finn2 = {L"Finn: Ozan! Lir hakkında söylediklerini duydum. Bu kadar güçlü bir şey nasıl bir ozanın elinde olabilir?"};
        message finn3 = {L"Sen: Finn, bu lirin gücü sandığından daha karmaşık. Ama onu korumak için ne gerekiyorsa yapacağım."};
        message finn4 = {L"Finn: Eğer bu kadar önemliyse, neden onu saklamıyorsun? Ya da bir yere gömmüyorsun?"};
        message finn5 = {L"Sen: (Gülümseyerek) Bazen bir şeyi saklamak, onu tehlikeye atmaktan daha büyük bir sorumluluk getirir. Bu liri göremeyen biri bile hissedebilir."};
        message finn6 = {L"\0"};
        message finn[10] = {finn6, finn5, finn4, finn3, finn2, finn1};
        for (int i = 0; i < 5; ++i) {
            sendToRightSection(finn[i]);
        }


    }
    if (MISSION_COUNTER == 5 ) {
        message ozan1 = {L"(Ozan masada yalnız başına oturur, lirini dikkatle inceler. Geçmişindeki olaylar ve sorumlulukları arasında gidip gelir.)"};
        message ozan2 = {L"Sen: Bu lir… gerçekten tüm bunlara değer mi? Sebinchi, Broski, Lyria… hepsini bu sır yüzünden tehlikeye atıyorum."};
        message ozan3 = {L"\0"};
        message ozan[10] = {ozan3, ozan2, ozan1};
        for (int i = 0; i < 2; ++i) {
            sendToRightSection(ozan[i]);
        }
    }

}

void dialoguePerson4() {
    if (MISSION_COUNTER == 2) {
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
    if (MISSION_COUNTER == 3) {
        message finn1 = {L"(Finn, bir masanın yanında durmuş, boş bir kadehi inceliyor. Seni görünce heyecanla yanına gelir.)"};
        message finn2 = {L"Finn: Ozan! Bir maceradan döndün, değil mi? Bana biraz bahseder misin? Hep dışarı çıkıp sizin gibi olmak istiyorum."};
        message finn3 = {L"Sen: Bu işler düşündüğün kadar eğlenceli değil, Finn. Hayatta kalmak için her gün yeni bir mücadeleye atılmak zorundasın."};
        message finn4 = {L"Finn: (Bir an ciddileşir, sonra gülümser) Ama senin gibi bir ozan, bu mücadeleleri birer şarkıya dönüştürebilir. Belki bir gün ben de senin şarkılarında bir yer bulurum."};
        message finn5 = {L"\0"};
        message finn[10] = {finn5, finn4, finn3, finn2, finn1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(finn[i]);
        }


    }
    if (MISSION_COUNTER == 4) {
        message hanci1 = {L"(Hancı, tezgâhın arkasında bardakları yıkarken seni bir süre izler. Sonunda, hafifçe gülümseyerek sana seslenir.)"};
        message hanci2 = {L"Hancı: Ozan, burada kimse sırlarını uzun süre saklayamaz. Ama şunu bil ki, bazen en büyük tehlike sırların değil, sırları korumaya çalışmaktır."};
        message hanci3 = {L"Sen: Haklısın. Ama bu sırları açığa çıkarmak, daha büyük bir felaketi beraberinde getirebilir."};
        message hanci4 = {L"Hancı: (Başını sallar) Pekâlâ. Ama bir gün, doğru kişilere güvenmenin zamanı gelecek. O zamana kadar hayatta kalmaya çalış."};
        message hanci5 = {L"\0"};
        message hanci[10] = {hanci5, hanci4, hanci3, hanci2, hanci1};
        for (int i = 0; i < 4; ++i) {
            sendToRightSection(hanci[i]);
        }


    }
    if (MISSION_COUNTER == 5 ) {
        message althara1 = {L"Althara: Ozan, yüzündeki bu ifade... yükün daha da ağırlaşmış gibi görünüyor. Artık bu lirin sırlarını paylaşmanın zamanı gelmedi mi?"};
        message althara2 = {L"Sen: Bu sır, yalnızca benim sırtımda taşıyabileceğim bir yük. Onu paylaşmak daha fazla insanı tehlikeye atabilir."};
        message althara3 = {L"Althara: (Derin bir nefes alır ve gülümser) Bazen sırlar, onları sakladıkça daha büyük bir tehlike haline gelir. Belki de sırlarını paylaşmak değil, doğru kişilere güvenmek çözüm olabilir. Ama şunu unutma: sırların ne kadar güçlü olursa, düşmanların da o kadar yakın olur."};
        message althara4 = {L"\0"};
        message althara[10] = {althara4, althara3, althara2, althara1};
        for (int i = 0; i < 3; ++i) {
            sendToRightSection(althara[i]);
        }
    }

}