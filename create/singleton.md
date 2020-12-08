# 单例（Singleton）

## 目标

确保一个类仅实例化一个对象，并且提供一个全局的访问点。


## 原因

某些情况下，一个系统中仅有一个（或几个）实例的需要。例如，一个学校仅有一个校长；一个电脑系统中，仅有一个文件系统。

全局变量可以使变量可全局访问的，但是不能保证其不被多次实例化。更好的方法是让类自己负责实例化的管理和追踪。这样做不仅能确保单例，而且能提供一个访问单例的方法。而且代码更内聚。


## 适用

- 整个系统仅需要对某个类实例化一个对象。并且有一个公共的访问点。

- 当单个实例需要被子类国展，并且客户端能够适用被扩展的实例，而不用更新原有代码。

## 优点：

1. 控制单例的访问。由于类持有它自己的单例，它能够严格控制如何以及何时能够访问单例。

2. 优化命名空间。单例是全局变量的改良版。通过将单例限制在自己的命名空间内从而避免污染全局的命名空间。

3. 操作和表示得访问权限优化。单例类可能会被子类扩展，配置实例化扩展的子类非常方便。你甚至可以在运行时配置使用的需要的类实例。

4. 控制实例化的数量。该设计模式可以非常方便的控制实例化的数量。而且，你可以使用相同的方法控制应用需要使用的实例数量。仅仅需要修改访问实例的函数即可。

5. 比类操作更灵活。?


## 实现

1. 隐藏构造函数，避免类被随意的实例化。

2. 使用成员方法创建对象，在创建之前先判断，从而保证仅有一个（固定几个）对象被实例化。该操作符拥持有单例的变量的访问权限，它却保该变量在返回之前，被实例化并且仅被实例化一次。

3. 通常使用静态成员函数来访问单例。单例同样被顶一个为一个静态成员变量以全局只有唯一的实例。



