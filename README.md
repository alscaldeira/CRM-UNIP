# CRM-UNIP

Este projeto é um trabalho de faculdade. Ficará disponível para downlad em casos de estudo, uso e modificações de acordo com a licença MIT.

![image](https://user-images.githubusercontent.com/52506164/188888619-eecc86c0-015a-490e-81b6-d3cb4a5ad4ed.png)

## Sobre o projeto

Com base em uma empresa fictícia de investimentos, esse software vai servir tanto para os clientes quanto para os funcionários.
Como uma empresa (fictícia) responsável por administrar a carteira de investimento dos nossos clientes, gostamos de conhecer nossos clientes para chegar ao tipo de investimento mais apropriado para cada um. Então não se assuste se perguntarmos sobre seu relacionamento com o dinheiro na tela de cadastro.
Temos uma equipe de analistas financeiros capacitada para investir de acordo com os seus futuros planos.

### Detalhes do projeto

Este projeto exige 3 tipos de usuários diferentes que serão esclarecidos [neste tópico](#projeto_detalhes). Cada tipo de usuário tem suas permissões e responsabilidades. A seguir será passado por cada tela e comportamento do software, caso esteja mais interessado na parte prática siga as instruções de [como rodar o projeto](#como_rodar_projeto)

#### Tela de login

Ao iniciar o projeto, o usuário se depara com a tela de login. Caso ele não tenha um login e não é funcionário da Barsi, é possível cadastrar uma conta apenas selecionando a opção cadastrar.

#### Tela de cadastro

Na tela de cadastro vão ser pedidas algumas informações sobre o cliente, seus planos futuros, seu momento atual e seu relacionamento com o dinheiro, todas as perguntas poderão ser respondidas com pontos entre 0 a 10 para entender melhor qual é o perfil do cliente ao realizar uma função de média aritmética.

#### Visão do cliente:

##### Tela principal

Nessa tela terá opções como baixar relatório de investimentos, edição de planejamento, investir e informações sobre o plano contratado na Barsi.

##### Tela de edição de planejamento

A tela de edição de planejamento tem a função de editar o tipo da carteira. 

##### Tela de investimento

A tela de investimento permite com que o cliente insira mais valor a ser investido pelos analistas financeiros.

##### Tela de informações sobre o plano contratado na Barsi

Nessa tela o cliente consegue ver qual plano contratual ele está usando e mudar o plano caso quiser (antes do plano contratual ser mudado, vai precisar esperar encerrar o período do contrato atual).

#### Visão do analista financeiro:

##### Tela principal

Na tela principal a primeira opção será de baixar o relatório de sua equipe, contendo os dados das carteiras dos clientes pelos quais são responsáveis.
A segunda opção leva para um tela de modificação de carteira de um devido cliente que é sempre acessado pelo id por questões de segurança.

##### Tela de modificação de carteira

Apresentando detalhes da carteira do cliente que foi acessado pelo id antes de entrar nessa tela. É possível modificar as ações feitas nesta carteira. (Entrar em detalhes na reunião da equipe de desenvolvimento com o tema de quais ações de investimento são possíveis dentro do sistema).

#### Visão do ADM:

##### Tela principal

Na tela principal a primeira opção será de baixar o relatório dos resultados de cada equipe.
A segunda opção será de alterar informações do analista, que altera os dados básicos do analista ou realoca o mesmo em alguma outra [equipe](tipos_analista).
A terceira opção adiciona um novo analista financeiro.

## Instruções para rodar o projeto <a name="como_rodar_projeto"></a> 

### Baixando compilador para C/C++

#### Windows:

1. Baixe [MinGW](https://nuwen.net/files/mingw/mingw-18.0-without-git.exe) e faça o processo de instalação.
2. [Edite a variável de ambiente Path](https://pt.stackoverflow.com/a/5030) e adicione o caminho `C:\MinGW\bin`
3. Abra o prompt de comando e digite o comando `gcc --version`
4. Você provavelmente verá a versão do compilador C/C++

#### Mac:

Os passos de instalação do compilador C/C++ mencionados a seguir foram baseados em pesquisas feitas em diversos sites mas não foram testadas. Caso não funcione, procure por um tutorial de algum autor de sua confiança.

1. Registre uma conta de desenvolvedor na [Apple](https://developer.apple.com/downloads/index.action)
2. Baixe a ferramenta para linha de comando [Xcode](https://developer.apple.com/xcode/)
3. Depois do arquivo .dmg for baixado, uma pequena janela vai aparecer mostrando esse arquivo `Command Line Tools.mpkg`
4. Abra o terminal e digite o comando `gcc --version`
5. Você provavelmente verá a versão do compilador C/C++

#### Distribuições linux baseadas em Debian:

1. Entre o comando `sudo apt install gcc`
2. Abra o terminal e digite o comando `gcc --version`
3. Você provavelmente verá a versão do compilador C/C++

#### Em caso de erro da instalação em algum sistema operacional:
Caso o prompt retornar algum erro no passo 4, é indicado copiar o erro e pesquisar por uma solução no Google.
Na maioria dos casos o erro já foi experienciado por outras pessoas, algumas delas postaram o erro em alguns fóruns da internet e o erro já foi solucionado.
Então tente procurar primeiro por uma solução no site [Stack Overflow](https://stackoverflow.com/).


### ------------------------------------ FINALIZAR AS INSTRUÇÕES DE INSTALAÇÃO

## Detalhes técnicos do projeto <a name="projeto_detalhes"></a> 

### Os 3 tipos de usuários do sistema

1. ADM:
  São responsáveis por administrar as equipes de analistas financeiros, podendo mover um analista para outra equipe, criando ou removendo um usuário analista.
  Suas permissões são sempre voltadas aos analistas, como por exemplo: suas equipes e visualização de suas performances nas respectivas tarefas.
  
2. Analista Financeiro:
  São responsáveis por administrar a carteira do cliente.
  Analistas financeiros estão divididos entre equipes de [ICP, IMP e ILP](#tipos_analista).
  Suas permissões se baseiam na carteira do cliente, podendo adaptar a carteira adicionando e removendo ações.
  
3. Cliente:
  Como personagem principal do produto, pode resgatar o dinheiro investido, mudar de planejamento (como por exemplo decidir que prefere investir a curto prazo mesmo sabendo que os riscos aumentariam), consegue também cancelar o plano mesmo ciente da multa hehehe.
  
  ### Os 3 tipos de Analistas <a name="tipos_analista"></a> 
  * ICP (Investimentos de Curto Prazo)
  * IMP (Investimentos de Médio Prazo)
  * ILP (Investimentos de Longo Prazo)

### Estrutura do projeto

O projeto está estruturado de uma forma muito simples.
Existem arquivos responsáveis pela visualização das telas que estão na pasta view, arquivos responsáveis pelo tratamento de dados que estão na pasta controller e arquivos responsáveis pela transação de dados que estão na pasta model.

![mvc](https://www.cybermedian.com/pt/wp-content/uploads/sites/11/2022/02/img_6212df40ef951.png "Exemplo de relacionamento entre model, view e controller")
