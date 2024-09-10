
<h1>P03D20</h1>

<p>Функция <code>tokenize</code> в предоставленной программе на C предназначена для разбора инфиксного арифметического выражения на отдельные токены. Каждый токен может быть числом, оператором, функцией, переменной (например, <code>x</code>) или круглой скобкой. Цель этой функции — упростить последующие шаги обработки, такие как преобразование инфиксного выражения в обратную польскую запись (RPN).</p>
<p>Вот подробное объяснение того, как работает функция <code>tokenize</code>, построчно:</p>
<h3 id="function-tokenize">Функция: <code>tokenize</code></h3>
<pre class=" language-c"><code class="prism language-c"><span class="token keyword">void</span> <span class="token function">tokenize</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> infix<span class="token punctuation">,</span> <span class="token keyword">char</span> tokens<span class="token punctuation">[</span>MAX_EXPR_SIZE<span class="token punctuation">]</span><span class="token punctuation">[</span>MAX_EXPR_SIZE<span class="token punctuation">]</span><span class="token punctuation">,</span> <span class="token keyword">int</span> <span class="token operator">*</span>tokenCount<span class="token punctuation">)</span> <span class="token punctuation">{</span>
</code></pre>
<ul>
<li><strong>Цель</strong>: Эта функция принимает инфиксное выражение в качестве входных данных и разбивает его на токены.</li>
<li><strong>Параметры</strong>:
<ul>
<li><code>const char* infix</code>: Входная строка, содержащая инфиксное выражение.</li>
<li><code>char tokens[MAX_EXPR_SIZE][MAX_EXPR_SIZE]</code>: Массив для хранения полученных токенов.</li>
<li><code>int *tokenCount</code>: Указатель на целое число, в котором будет храниться количество токенов.</li>
</ul>
</li>
</ul>
<pre class=" language-c"><code class="prism language-c"> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> j <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> k <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token operator">*</span>tokenCount <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
</code></pre>
<ul>
<li><strong>Инициализация</strong>:
<ul>
<li><code>i</code> — это индекс для перебора строки <code>infix</code>.</li>
<li><code>j</code> — это индекс для построения каждого токена.</li>
<li><code>*tokenCount</code> инициализируется нулем, что будет считать количество созданных токенов.</li>
</ul>
</li>
</ul>
<pre class=" language-c"><code class="prism language-c"> <span class="token keyword">while</span> <span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">!=</span> <span class="token string">'\0'</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
</code></pre>
<ul>
<li><strong>Цикл</strong>: Функция перебирает каждый символ во входной строке <code>infix</code> до тех пор, пока не будет достигнут нулевой терминатор, указывающий на конец строки.</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isdigit</span><span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">==</span> <span class="token string">'.'</span> <span class="token operator">&amp;&amp;</span> <span class="token function">isdigit</span><span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i <span class="token operator">+</span> <span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
</code></pre>
<ul>
<li><strong>Числа</strong>: Функция проверяет, является ли текущий символ цифрой или десятичной точкой, за которой следует цифра, что указывает на начало числа.</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">            j <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
            <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token function">isdigit</span><span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">||</span> infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">==</span> <span class="token string">'.'</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
                tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span>j<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> infix<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span><span class="token punctuation">;</span>
            <span class="token punctuation">}</span>
            tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span>j<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token string">'\0'</span><span class="token punctuation">;</span>
            <span class="token punctuation">(</span><span class="token operator">*</span>tokenCount<span class="token punctuation">)</span><span class="token operator">++</span><span class="token punctuation">;</span>
</code></pre>
<ul>
<li><strong>Обработка чисел</strong>:
<ul>
<li>Вложенный цикл собирает все последовательные цифры и десятичные точки в один токен.</li>
<li><code>j</code> используется для построения токена символ за символом.</li>
<li>После цикла токен завершается нулем, чтобы образовать действительную строку.</li>
<li>Количество токенов увеличивается.</li>
</ul>
</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">        <span class="token punctuation">}</span> <span class="token keyword">else</span> <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalpha</span><span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
</code></pre>
<ul>
<li><strong>Функции или переменные</strong>: Если символ является буквенным, это указывает на то, что это либо функция (например, <code>sin</code> или <code>cos</code>), либо переменная (например, <code>x</code>).</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">            j <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
            <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token function">isalpha</span><span class="token punctuation">(</span>infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
                tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span>j<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> infix<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span><span class="token punctuation">;</span>
            <span class="token punctuation">}</span>
            tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span>j<span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token string">'\0'</span><span class="token punctuation">;</span>
            <span class="token punctuation">(</span><span class="token operator">*</span>tokenCount<span class="token punctuation">)</span><span class="token operator">++</span><span class="token punctuation">;</span>
</code></pre>
<ul>
<li><strong>Обработка функций/переменных</strong>:
<ul>
<li>Подобный вложенный цикл собирает все последовательные буквенные символы в один токен.</li>
<li>Это позволяет обрабатывать функции с несколькими символами и переменные с одним символом.</li>
<li>Токен завершается нулем, и количество токенов увеличивается.</li>
</ul>
</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">        <span class="token punctuation">}</span> <span class="token keyword">else</span> <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">strchr</span><span class="token punctuation">(</span><span class="token string">"+-*/^()"</span><span class="token punctuation">,</span> infix<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
</code></pre>
<ul>
<li><strong>Операторы и скобки</strong>: Функция проверяет, является ли символ одним из операторов (+, -, *, /, ^) или скобок ((, )).</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">            tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span><span class="token number">0</span><span class="token punctuation">]</span> <span class="token operator">=</span> infix<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span><span class="token punctuation">;</span>
            tokens<span class="token punctuation">[</span><span class="token operator">*</span>tokenCount<span class="token punctuation">]</span><span class="token punctuation">[</span><span class="token number">1</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token string">'\0'</span><span class="token punctuation">;</span>
            <span class="token punctuation">(</span><span class="token operator">*</span>tokenCount<span class="token punctuation">)</span><span class="token operator">++</span><span class="token punctuation">;</span>
</code></pre>
<ul>
<li><strong>Обработка операторов/скобок</strong>:
<ul>
<li>Каждый оператор или скобка рассматривается как токен с одним символом.</li>
<li>Символ непосредственно сохраняется как токен, завершается нулем, и количество токенов увеличивается.</li>
</ul>
</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">        <span class="token punctuation">}</span> <span class="token keyword">else</span> <span class="token punctuation">{</span>
            i<span class="token operator">++</span><span class="token punctuation">;</span> <span class="token comment">// Skip any invalid characters</span>
        <span class="token punctuation">}</span>
    <span class="token punctuation">}</span>
<span class="token punctuation">}</span>
</code></pre>
<ul>
<li><strong>Некорректные символы</strong>: Любые символы, которые не соответствуют вышеуказанным категориям, просто пропускаются, и цикл продолжается со следующим символом.</li>
</ul>
<h3 id="summary">Резюме</h3>
<p>Функция <code>tokenize</code> систематически разбивает инфиксное выражение на управляемые компоненты, гарантируя, что числа, операторы, функции, переменные и скобки обрабатываются соответственно. Эта токенизация упрощает обработку выражения на последующих этапах, таких как преобразование в обратную польскую нотацию (RPN) и оценка.</p>
<p>Алгоритм шунтирования Дейкстры используется в программе для преобразования инфиксного арифметического выражения (например, <code>3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3</code>) в постфиксное выражение, также известное как обратная польская нотация (RPN) (например, <code>3 4 2 * 1 5 - 2 3 ^ ^ / +</code>). Это преобразование необходимо, потому что RPN можно легче оценивать с использованием подхода на основе стека, не учитывая приоритет операторов или скобок. Вот как работает алгоритм шунтирования в этой конкретной программе:</p>
<h3 id="function--infixtorpn">Функция: <code>infixToRPN</code></h3>
<ol>
<li><strong>Инициализация:</strong>
<ul>
<li>Инициализируется <code>StringStack</code> с именем <code>stack</code> для временного хранения операторов и имен функций.</li>
<li>Входное <code>infix</code> выражение токенизируется в <code>tokens</code>, что разбивает выражение на числа, операторы и скобки.</li>
<li>Подготавливается выходной <code>rpn</code> массив для хранения результирующего выражения RPN.</li>
<li><code>rpnLength</code> инициализируется нулем для отслеживания количества элементов в выражении RPN.</li>
</ul>
</li>
<li><strong>Итерация токенов:</strong>
<ul>
<li>Алгоритм проходит по каждому токену в токенизированном <code>infix</code> выражении.</li>
</ul>
</li>
<li><strong>Обработка чисел и переменных:</strong>
<ul>
<li>Если токен является числом или переменной <code>x</code>, он напрямую добавляется в выходной <code>rpn</code> вывод, так как операнды напрямую переходят в выход в RPN.</li>
</ul>
</li>
<li><strong>Обработка функций:</strong>
<ul>
<li>Если токен является функцией (например, <code>sin</code> или <code>cos</code>), он помещается в <code>stack</code>.</li>
</ul>
</li>
<li><strong>Обработка левой скобки <code>(</code>:</strong>
<ul>
<li>Левая скобка помещается в <code>stack</code>, чтобы указать на начало подвыражения.</li>
</ul>
</li>
<li><strong>Обработка правой скобки <code>)</code>:</strong>
<ul>
<li>Когда встречается правая скобка, алгоритм извлекает операторы из <code>stack</code> в выходной <code>rpn</code> до тех пор, пока не встретится левая скобка в <code>stack</code>, которая затем игнорируется.</li>
<li>Если функция находится на вершине <code>stack</code> после встречи левой скобки, она также извлекается в <code>rpn</code>.</li>
</ul>
</li>
<li>*<em>Обработка операторов (+, -, <em>, /, ^):</em></em>
<ul>
<li>Для токена оператора алгоритм сравнивает его приоритет с оператором на вершине <code>stack</code>.</li>
<li>Пока на вершине находится оператор с равным или большим приоритетом, оператор извлекается из <code>stack</code> в выходной <code>rpn</code>.</li>
<li>Текущий токен оператора затем помещается в <code>stack</code>.</li>
</ul>
</li>
<li><strong>Конец выражения:</strong>
<ul>
<li>После обработки всех токенов все оставшиеся операторы в <code>stack</code> извлекаются в выходной <code>rpn</code>. Это гарантирует, что все операторы будут перемещены в выходной результат после обработки всех входных данных.</li>
</ul>
</li>
</ol>
<h3 id="precedence-handling">Обработка приоритетов:</h3>
<ul>
<li>Функция <code>precedence</code> назначает уровни операторам (<code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>, <code>^</code>), чтобы обеспечить правильный порядок операций, при этом <code>^</code> имеет наивысший приоритет, а <code>+</code>/<code>-</code> — наинизший.</li>
</ul>
<h3 id="example-conversion">Пример преобразования:</h3>
<p>Для выражения типа <code>3 + 4 * 2</code> алгоритм Шунтинга обработает токены следующим образом:</p>
<ul>
<li><strong>Токен <code>3</code></strong>: Непосредственно добавлен в <code>rpn</code>.</li>
<li><strong>Токен <code>+</code></strong>: Добавлен в <code>stack</code>.</li>
<li><strong>Токен <code>4</code></strong>: Непосредственно добавлен в <code>rpn</code>.</li>
<li><strong>Токен <code>*</code></strong>: Имеет более высокий приоритет, чем <code>+</code>, поэтому добавлен в <code>stack</code>.</li>
<li><strong>Токен <code>2</code></strong>: Непосредственно добавлен в <code>rpn</code>.</li>
<li><strong>Конец</strong>: Извлекаем <code>*</code> и <code>+</code> из <code>stack</code> в <code>rpn</code>.</li>
</ul>
<p>Результирующая РПН: <code>3 4 2 * +</code> Этот алгоритм позволяет правильно преобразовывать любое корректное инфиксное выражение в РПН, которое затем может быть оценено с использованием простого алгоритма на основе стека. Программа использует это выражение РПН для оценки и построения графика функции, используя простую оценку постфиксных выражений.</p>
<p>Предоставленный код представляет собой программу на C, которая считывает арифметическое выражение от пользователя, преобразует его в Обратную Польскую Нотацию (РПН) с помощью алгоритма Шунтинга Дейкстры, оценивает выражение для диапазона значений x и строит график функции на текстовой координатной системе. Давайте рассмотрим код построчно и объясним его функциональность:</p>
<h3 id="header-files">Заголовочные файлы</h3>
<ol>
<li><code>#include &lt;stdio.h&gt;</code>: Подключает библиотеку стандартного ввода-вывода, которая предоставляет функции для операций ввода и вывода.</li>
<li><code>#include &lt;stdlib.h&gt;</code>: Подключает стандартную библиотеку, которая предоставляет функции для управления памятью, управления процессами, преобразований и других операций.</li>
<li><code>#include &lt;string.h&gt;</code>: Подключает библиотеку строк, которая предоставляет функции для работы со строками.</li>
<li><code>#include &lt;ctype.h&gt;</code>: Подключает библиотеку символов, которая предоставляет функции для тестирования и отображения символов.</li>
<li><code>#include &lt;math.h&gt;</code>: Подключает математическую библиотеку, которая предоставляет математические функции, такие как <code>sin</code>, <code>cos</code> и <code>pow</code>.</li>
</ol>
<h3 id="macros">Макросы</h3>
<ol>
<li><code>#define MAX_STACK_SIZE 100</code>: Определяет максимальный размер стека, используемого в программе.</li>
<li><code>#define MAX_EXPR_SIZE 100</code>: Определяет максимальный размер арифметического выражения.</li>
<li><code>#define WIDTH 80</code>: Определяет ширину графика.</li>
<li><code>#define HEIGHT 25</code>: Определяет высоту графика.</li>
<li><code>#define CENTER_Y 12</code>: Определяет центральную координату y для построения графика.</li>
<li><code>#define PI 3.14159265358979323846</code>: Определяет постоянную ПИ.</li>
</ol>
<h3 id="data-structures">Структуры Данных</h3>
<ol>
<li><code>typedef struct { double items[MAX_STACK_SIZE]; int top; } Stack;</code>: Определяет структуру стека для хранения значений типа double с <code>top</code>, который отслеживает верхнюю часть стека.</li>
<li><code>typedef struct { char items[MAX_STACK_SIZE][MAX_EXPR_SIZE]; int top; } StringStack;</code>: Определяет структуру стека для хранения строк (токенов) с <code>top</code>, который отслеживает верхнюю часть стека.</li>
</ol>
<h3 id="function-declarations">Объявления Функций</h3>
<p>14-26. Объявления функций для операций со стеком, преобразования выражений, оценки и построения графиков.</p>
<h3 id="main-function">Главная Функция</h3>
<ol>
<li><code>int main() { ... }</code>: Главная функция программы.</li>
<li><code>char infix[MAX_EXPR_SIZE];</code>: Объявляет массив для хранения входного инфиксного выражения.</li>
<li><code>char rpn[MAX_EXPR_SIZE][MAX_EXPR_SIZE];</code>: Объявляет массив для хранения преобразованного выражения РПН.</li>
<li><code>int rpnLength;</code>: Объявляет целое число для хранения длины выражения РПН.</li>
<li><code>printf("Введите арифметическое выражение: ");</code>: Запрашивает у пользователя ввод арифметического выражения.</li>
<li><code>fgets(infix, MAX_EXPR_SIZE, stdin);</code>: Считывает входное выражение из стандартного ввода.</li>
<li><code>infix[strcspn(infix, "\n")] = '\0';</code>: Удаляет символ новой строки из входного выражения.</li>
<li><code>infixToRPN(infix, rpn, &rpnLength);</code>: Преобразует инфиксное выражение в РПН.</li>
<li><code>printf("Построение графика:\n");</code>: Печатает сообщение, указывающее на начало построения графика.</li>
<li><code>drawGraph(rpn, rpnLength);</code>: Строит график, используя выражение РПН.</li>
<li><code>return 0;</code>: Возвращает 0, чтобы указать на успешное выполнение.</li>
</ol>
<h3 id="stack-operations-for-double">Операции со Стеком для Double</h3>
<p>38-42. Функция <code>push</code> добавляет значение типа double в стек. 43-47. Функция <code>pop</code> удаляет и возвращает верхнее значение типа double из стека.</p>
<h3 id="stack-operations-for-strings">Операции со Стеком для Строк</h3>
<p>48-52. Функция <code>pushString</code> добавляет строку в стек строк. 53-57. Функция <code>popString</code> удаляет и возвращает верхнюю строку из стека строк.</p>
<h3 id="operator-precedence-and-type-checking">Приоритет Операторов и Проверка Типов</h3>
<p>58-67. Функции для определения приоритета операторов и проверки, является ли токен оператором или функцией.</p>
<h3 id="tokenization">Токенизация</h3>
<p>68-98. Функция <code>tokenize</code> разбивает входное инфиксное выражение на токены, обрабатывая числа, функции, операторы и скобки.</p>
<h3 id="infix-to-rpn-conversion">Преобразование Инфиксного Выражения в РПН</h3>
<p>99-133. Функция <code>infixToRPN</code> преобразует инфиксное выражение в РПН, используя алгоритм Шунтинга Дейкстры.</p>
<h3 id="rpn-evaluation">Оценка РПН</h3>
<p>134-158. Функция <code>evaluateRPN</code> оценивает выражение РПН для заданного значения <code>x</code>.</p>
<h3 id="graph-drawing">Построение Графиков</h3>
<p>159-193. Функция <code>drawGraph</code> строит график выражения в диапазоне значений <code>x</code>, используя текстовую координатную систему. Эта программа предоставляет базовую реализацию парсера выражений и построителя графиков, позволяя пользователям визуализировать простые математические выражения, включающие базовые арифметические операции и функции, такие как <code>sin</code> и <code>cos</code>.</p>
