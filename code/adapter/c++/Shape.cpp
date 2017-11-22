/*----------------------- 两个需要匹配的接口 -----------------------*/
/* 要适配的接口
* Shape 是自己拥有的接口，可以理解为自己项目中的接口。
*/
class Shape {
public:
    Shape();
    virtual void getBouningBox(Point& bottomLeft, Point& topRight) const; // 常成员函数，不会修改任何类的成员数据的值
    virtual Manipulator* CreateManipulator() const;
};

/* 被适配的接口（已经实现了功能，但是又和自己项目接口不匹配的类
*  TextView 是其它项目中的接口实现。已经实现了功能，可以使用。但是接口和自己项目的接口不匹配。
* 需要适配。
*/
class TextView {
public:
    TextView();
    void getOrigin(Coord& x, Coord& y) const; // 接口不匹配体现在通过原点和宽，高来定会位置的边界。
    void getExtent(Coord& width, Coord& height) const;// 宽， 高
    virtual bool isEmpty() const;
}

/*--------------------------------- 类适配器 ------------------------------*/

/** 类适配器
* 类适配采多重继承适配接。类适配的关键是继承要适配的接口，同时继承被适配的实现。通常 C++中作出这一区分的方法是: 用公共式继承接接口;
* 用私有方式继承接被适配的实现。
*/
class TextShape: public Shape, private TextView {
public:
    TextShape();
    virtual void getBouningBox(Point& bottomLeft, Point& topRight) const;
    virtual bool isEmpty() const;
    virtual Manipulator* CreateManipulator() const;
}

// BoundingBox操作对TextView的接口进行转换使之匹配 Shape的接 。这里是获取View边界的。
void TextShape::getBouningBox(Point& bottomLeft, Point& topRight) const {
    Coord bottom, left, width, height;
    getOrigin(bottom, left);
    getExtent(width, height);
    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShape::isEmpty() const {
    return TextView:: isEmpty();
}


// 最后，我们定义 CreateManipulator(TextView 不支持该操作)，假定我们已经实现支持TextShape操作的类 TextManipulator。

Manipulator* TextShape::getCreateManipulator () const {
    return new TextManipulator(this);
}

/*--------------------------------- 对象适配器 ----------------------------*/
/* 对象适配器采用对象组合的方法将不同的接口和类组合在一起。 在该方法中，适配器TextShape维护一个指向
* TextView的指针。
*/
class TextShape: public Shape {
public:
    TextShape(TextView*);
    virtual void getBouningBox(Point& bottomLeft, Point& topRight) const;
    virtual bool isEmpty() const;
    virtual Manipulator* CreateManipulator() const;
private:
    TextView* textView;
}

TextShape::TextShape( TextView view) {
    textView = view;
}

void TextShape::getBouningBox(Point& bottomLeft, Point& topRight) const {
    Coord bottom, left, width, height;
    textView->getOrigin(bottom, left);
    textView->getExtent(width, height);
    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShape::isEmpty() const {
    return textView->isEmpty();
}

/* 对于新增加的功能，类适配器和对象适配器是完全相同的。因为它是从零开始，没有任何已有代码可用 */
Manipulator* TextShape::getCreateManipulator () const {
    return new TextManipulator(this);
}
