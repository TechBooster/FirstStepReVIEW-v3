={textlint} 文章をよくする改善ポイント

本を作るうえで苦労することのひとつに統一感があります。文章が途中で変わっていないか、主張が変わっていないか、
タイトルと内容が変わったり本の最後のほうで文体が変わったりするとやはりもったいないなぁという風になりますよね。

せっかく書いたのだし細部に注意して読みやすい本にしたいという方にむけて文章が断然よくなる改善ポイントをお伝えします。

すべての文章がかくあるべきという意味ではありませんが、技術書に顕著な評価軸として文章のわかりやすさがあります。これは仕事でのドキュメンテーションなどにも活きる知識ですので、ここぞとばかりに覚えておいて損はありません。

細かい内容に関してはわたしたち本書の筆者であるmhidakaとvvakameが書いた技術的な文章を書くための手引も役に立つかでしょう。

 : 技術的な文章を書くための第0歩 ～読者に伝わる書き方～
   @<href>{http://qiita.com/mhidaka/items/c5fe729716c640b50ff7}
 : 技術的な文章を書くための1歩、2歩、3歩
   @<href>{http://qiita.com/vvakame/items/d657baf26cf83ac98bd0}

次では技術書として注意したらよいポイントをいくつか列挙します。指摘内容の大小といった粒度に差はありますが、重要だと思う項目からの紹介です。

== 主張の統一
ひとつの文章にたくさんの主張を入れると読む人は混乱してしまいます。
読みやすさを考えてシンプルな構成を選びましょう。

 * 特定のコンテキストでは、ひとつの主張のみ扱う（章、節、項で主張の大小はある）
 * 初出の単語、概念は登場時点で説明する

たとえば章のはじめには導入（リード文）を用意してまとめを説明して読者と記事のマッチングをはかります。
書いているうちに節のタイトルが本文と異なる場合もありますので主張を意識して読みなおすことが大切です。
執筆中は初出の単語、概念など気づかない場合があります。読みなおすことで初出の単語の発見や、
前後の文章を入れ替えて主張を理解しやすくするなど、本の構成をよりよく変えられます。

== 文中の文言と装飾を書籍にあわせる

#@# prh:disable
文章を書いていると上下を意識して「以上が」「以下のとおりです」など書きたくなりますが
組版の都合で上下が明らかでない場合があります。次のページにいってしまったりするわけですね。
それぞれ「前述のとおり」「次のとおりです」で置き換えるとよいでしょう@<fn>{lint}。
これらのために、@<chapref>{review-introduction}で解説するリストや図があるわけです。

//footnote[lint][後述のprhで技術書向きの校正を行えます。自分好みにカスタマイズするとよいでしょう]

また図、表、リストについては次のことを念頭に構成してください。

 * 図、表、リストの登場前に本文中から参照する（＠<img>、＠<list>など）
 * 登場前に内容を簡単に説明する一文を書く
 * 登場後に詳しい解説を書く

これらを守ることで何について述べているのかわかりやすくなり、読者が読んだときの唐突感や投げっぱなし感がなくなります。

装飾には、いわゆる太字、斜体などフォントの見た目を変えて読みやすくする意図があります。
しかし利用基準を定めて守るほうが難しく、一貫性を保つのが作業量的にしんどい側面もあります。
大事な内容であれば、装飾を多用せず文章中で注意喚起したほうがよっぽどよいでしょう。
装飾が必要なときは編集担当者がチェックできる基準でのみ実施すべきです。
#@# REVIEW vvakame review-introduction.reで結構文字装飾使ってる…
#@# 改訂にあわせて減らしておいたよ。強調はstrongを一部だけで、ファイル名はttで装飾に統一している。

たとえばリスト中の変数名ではコードとして装飾するなど明確な基準がある装飾であれば統一感がありますね。

== 文体の統一
文体は著者の味となるため過剰な編集は好みませんが、それでも次のような表現は
編集段階で変更しています。

 * ネガティブな表現を利用しない
 * 体言止め、話し言葉は利用しない
 * ですます調と、である調を混在しない
 * 思いますなど感想にならないようにする
 * 文章中の記号は全角が基本（特にカッコ）
 * 文章中の英単語は前後にスペースを入れないで空きを詰める

ネガティブな表現は読者の心証を悪くします。期待して本を読んでいる読者に、
デメリットだけでなくメリットも感じてもらえるように表現をポジティブに改めます。
また技術書であれば平易な表現を心がけて読者の理解に努める方針のもと、
著者の文体を壊さない程度に調整します。
「～だと思います」という文章であれば「です」と編集したり、
「～することができます」という表現であれば簡潔に「～できます」と縮めています。

編集時には想定読者になりきって読みやすい文章を追及しましょう。

見た目に影響する話では、半角記号は基本的に英字に合わせてフォントが作られています。
文章中で表現として使う場合、記号は全角を利用してください。
メソッド名、プログラムのソースコードからの引用はその限りではありません。

とくに半角カッコはフォントの高さが全角文字と異なるため、沈んだ印象を受けます。
全角カッコを利用するようにしてください。

== 長い文章は分割する

著者にとって技術書に登場する文章は、なんども咀嚼して推敲を重ねた馴染み深い存在です。しかし本が読者に渡ったあとには文章が突如として、はじめて読む存在に変貌します。

書籍のなかに、おおむね3行を超える文章があったら2つ以上の文章に分割してください。お勧めは主語と述語（動詞）の距離を短く保つことです。

英語を勉強したときを思い出してみてください。ごく簡単な例文から学びはじめませんでしたか？This is a pen.というテキストを学んだあとにアリス・イン・ワンダーランドといった英語の古典的表現に踏み込んでいるはずです。技術書の文章も同様に、あまりに長いと読者が情報を取りこぼしやすくなります。読者は著者と同じバックグラウンドを備えているわけではありません。
前提とする知識量の違いから、どの部分がわかりにくいかといった著者自身による判断が難しいシーンもしばしばです。

複数の文章に分割するコツは、正確性をコントロールすることです。「AはBである。ただしCの条件を満たすときAはDとなる」この文章は最初の1文で原則を示し、続いての文で例外を伝えています。この構造であれば誤読の要素もなく混乱しにくいですよね。伝えたい内容の重要性を加味し、順序を操ってください。

おおむね3行を超える文章とは具体的には100文字を超える程度だと考えるといいでしょう。同様に@<kw>{段落,パラグラフ}の長さも短いほうがよいと考えるかもしれませんが、こちらはトレンドがあり、近年は5~10行程度で1段落とする程度の短さが増えています。ただし文章そのものが短ければ、段落が長くても読みやすさは維持できます。前述した主張の統一とも関連するのでテクニックも必要です。そのため本章で挙げたポイントを差し置いて気にするほどではありません。

== 校正支援ツールprhを導入する

校正支援用ツールとしてprh@<fn>{prh}があります。prhはproofread helperの略です。
proofreadで1単語だから略したらphだろ！とか言ってはいけません。

//footnote[prh][@<href>{https://github.com/prh/prh}]

#@# prh:disable
prhは単純にルールに従い、文字列を置き換えるだけのものです。
たとえば「例えば」と書いたときに「たとえば」に置き換えるよう促してくれます。
これを漢字をひらがなに「開く」操作といいます。

一般的な表現を用いることで文章を読みやすくする効果があります。
文章の質を高めるためにはこのような書き換え処理をたくさんこなす必要があるわけです。

TechBoosterでは原稿をみんなが書き終えた後、ひつじ（@mhidaka、サークル主催）くんが全員の原稿に手を加え、開く処理をいれるなどの作業を行っていました。
そこでprhを作成し編集者の作業から著者個人の作業に変換した@<fn>{crazy-mhidaka}わけです。
面白いもので、規則をルール化し記述できるようにしたことで著者の中での校正に対する関心も高まってきました。

肝心の使い方についてです。現状あまりコマンドラインツールとしての使い勝手はよくありません。
Visual Studio Codeというエディタで使えるExtensionsのvscode-language-reviewにはprhが組み込まれているため、vscode-language-review経由で使うのが楽でしょう。

//footnote[crazy-mhidaka][「すごい！校正の労力が半分になったぞ！だから前回の2倍の冊数作った！」ってヤツは言いました。クレイジー]

=== prhのセットアップ

prhの環境構築は次のコマンドで行えます。本セットアップは@<hd>{setup|vscode}のあとに作業してください。章構成の関係でインストール手順が分かれています。

//cmd{
npm install -g prh
npm install -g prh-languageserver
//}

コマンドラインから使うかもしれないので@<code>{-g}オプションでグローバルインストールにしていますが
プロジェクト単位でのインストールでも問題ありません。

Visual Studio Codeを起動し、サイドバーの上部にマーケットプレースの検索ウインドウがあるので検索ワード「prh」と入力してExtensionsを探してください（@<img>{vscode-prh}）。

//image[vscode-prh][拡張機能のprhをインストールする]{
//}

=== prhで校正する

#@# prh:disable
インストール後は本書のリポジトリを開いて試してみてください。@<tt>{メニュー > フォルダを開く}からFirstStepReVIEW-v3ディレクトリを対象とするとわかりやすいでしょう。
@<tt>{articles/prh.yml}ファイルがTechBoosterの設定ファイル@<fn>{prh_setting}です。prhによる校正はターミナルに表示します（@<img>{vscode-prh-warning}）。

//footnote[prh_setting][@<href>{https://github.com/prh/rules/blob/a05c35d285d08dc7ba0a78dd791160116d39e9f4/media/techbooster.yml}]

//image[vscode-prh-warning][修正候補をLint表示している様子]{
//}

@<tt>{prh.yml}ファイルを@<tt>{.re}ファイルと同じディレクトリに置くとvscode-language-reviewが校正用ルールとして参照してLintを表示します。
もしターミナルが出ていない場合、@<tt>{メニュー > 表示 > ターミナル}からウインドウの下部にある問題タブを開いてみてください。


類似のツールにはRedPen@<fn>{redpen}やtextlint@<fn>{textlint}などがあります。
さらなる文章の改善を目指すのであれば、これらのツールを利用してみるのもよいでしょう。

とはいえ、根本的に文章の目的と構造がしっかりしていないといくら枝葉末節を補ったところで意味はありません。
本章で示した指標はあくまで補助線だと考えて自分が表現したい技術を書くことを追求してください。書き終わりさえすれば校正フェーズの時間は睡眠を削って絞り出したりできます。あと一歩でよいものができるぞと感じたら自然と効率が上がるものです。しかし書き終わらないと始まりません。編集のつらいところですね@<fn>{early}。

//footnote[redpen][@<href>{http://redpen.cc/}]
//footnote[textlint][@<href>{http://efcl.info/2015/09/10/introduce-textlint/}]
//footnote[early][早く終わらせるぞという意気込みで作業をすると、なぜかちょっとだけ遅延して終わります。時間はあるだけ使うんですよ]

