# 构建者/生成器（Builder）

## 目标

将复杂对象的构建过程和它的表示分离，使相同的构建过程能够创建不同的表示。




## 动机

一个用于 RTF (Rich Text Format) 格式转换的阅读器应该能够将 RTF 转换成多种格式。阅读器可能将 RTF 文档转换成普通 ASCII 文本或者转换成可编辑的文本控件。然而问题在于，能够转换的类型可能会不断增加，因此它应该在不修改阅读器的同时很容易地添加新的转换。

一种方案是给 RTF 阅读器配置一个 TextConvertor 对象用于将 RTF 转换成其他文本表示形式。在 RTF 阅读器转换 RTF 文档时，它调用 TextConvertor 执行转换。每当 RTF 阅读器识别到 RTF 的标识时（普通文本或者 RTF 控制字），它产生一个对 TextConvertor 的调用对于标识进行转换。 TextConvertor 对象负责数据和 TRF 标识转换成特殊的格式。

TextConvertor 不同的子类负责不同格式的转换。例如，ASCIIConvertor 忽略任何非普通文本格式换砖的请求。TexConvertor 则会实现所有的请求以获取文本中的所有特殊信息产生 TeX 表示。一个 TextWidgetConvertor 则会产生一个复杂的用于界面对象，能够被用户查看和编辑文本内容。


每种转换器类将创建和组装复杂对象的机制隐藏在抽象接口的后面。转换器与阅读器分离，并负责转换 RTF 文档。

构建者模式描述了这些关系。 在该模式中每个转换器被称为一个构建者，而阅读器被称为导向器（director）。对于此示例，构建者模式将用于识别文本格式算法和一个转换器如何创建和表示得分离。这方便重用 RTF 阅读器的解析算法从 TRF 文档创建不同格式文本表示，只需要给 RTF 阅读器配置不同的 TextConvertor 子类即可。

这让我们可以重用RTFReader的解析算法来从RTF文档创建不同的文本表示，只需用TextConverter的不同子类配置RTFReader即可。

## 适用性

以下情况使用构建者模式：

- 构建复杂对象的算法应该独立于对象的创建和组装方式时。

- 被构造对象的构建过程必须允许有不同形式的表示时。

## 结构


## 组成

- Builder: (TextConverter)

- ConcreteBuilder (ASCIIConverter, TeXConverter, TextWidgetConverter) 

- Director (RTFReader) 

- Product (ASCIIText, TeXText, TextWidget)

## 协作

- 客户端创建 Director 对象，并用它期望的 Builder 对象配置它。

- 每当需要产品的一部分需要被构建时，Director 就通知 Builder。

- Builder 根据 director 的指示给产品添加新的部分。

- 客户端从构建器检索产品


- 主要作用：在用户不知道对象的建造过程和细节的情况下就可以直接创建复杂的对象。

- 如何使用：用户只需要给出指定复杂对象的类型和内容，建造者模式负责按顺序创建复杂对象（把内部的建造过程和细节隐藏起来）

- 解决的问题：
（1）、方便用户创建复杂的对象（不需要知道实现过程）
（2）、代码复用性 & 封装性（将对象构建过程和细节进行封装 & 复用）

注意事项：与工厂模式的区别是：建造者模式更加关注与零件装配的顺序，一般用来创建更为复杂的对象


