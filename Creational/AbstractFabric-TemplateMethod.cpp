#include <iostream>

using namespace std;

class Button
{
    public: 
    virtual void render() const = 0;
    virtual ~Button() = default;
};

class Checkbox
{
    public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};

class WinButton : public Button
{
    public:
    void render() const override
    {
        cout << "Render Windows button" << endl;
    }
};

class WinCheckbox : public Checkbox
{
    public:
    void render() const override
    {
        cout << "Render Windows checkbox" << endl;
    }
};


class MacButton : public Button
{
    public:
    void render() const override
    {
        cout << "Render Mac button" << endl;
    }
};

class MacCheckbox : public Checkbox
{
    public:
    void render() const override
    {
        cout << "Render Mac checkbox" << endl;
    }
};


// Abstract factory
class GUIFactory
{
public:
    virtual Button* createButton() const = 0;
    virtual Checkbox* createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};

class WinFactory : public GUIFactory
{
public:
    Button* createButton() const override
    {
        return new WinButton();
    }

    Checkbox* createCheckbox() const override
    {
        return new WinCheckbox();
    }
};

class MacFactory : public GUIFactory
{
public:
    Button* createButton() const override
    {
        return new MacButton();
    }

    Checkbox* createCheckbox() const override
    {
        return new MacCheckbox();
    }
};

// Template method
class Dialog
{
public:
    virtual ~Dialog() = default;

    virtual Button* createButton() const = 0;

    void renderWindow() const
    {
        Button* btn = createButton();

        cout << "Dialog initialized" << endl;
        btn->render();

        delete btn;
    }
};

class WindowsDialog : public Dialog
{
public:
    Button* createButton() const override
    {
        return new WinButton();
    }
};

class MacDialog : public Dialog
{
public:
    Button* createButton() const override
    {
        return new MacButton();
    }
};

int main()
{
    Dialog* dialog = new WindowsDialog();
    dialog->renderWindow();
    delete dialog;

    dialog = new MacDialog();
    dialog->renderWindow();
    delete dialog;


    GUIFactory* factory = new WinFactory();
    Button* btn = factory->createButton();
    Checkbox* chk = factory->createCheckbox();

    btn->render();
    chk->render();

    delete btn;
    delete chk;
    delete factory;

    return 0;
}