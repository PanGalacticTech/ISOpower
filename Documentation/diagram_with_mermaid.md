# Creating .md Diagrams with Mermaid



```mermaid
  graph TD;    
      A[Do I Want A Diagram]-- Yes -->B;
      A(Do I Want A Diagram)-- No -->C[text];
      B---->D;
      C---->D;
```

```mermaid
      graph LR
      A(Do I Want A Diagram)-- Yes -->B;
      A(Do I Want A Diagram)-- No -->C(Bottom Text);
      B(Test Text)---->D(Cylinder);
      C(Bottom Text)---->D[(Cylinder)];
      E((Round Boi)) -->F{This is Unrelated};
      F == Thick Line ==> E;
```




## Explanation

> graph TD = graph top down <br>
>  graph LR = graph left right


'''https://mermaid-js.github.io/mermaid/#/flowchart'''


