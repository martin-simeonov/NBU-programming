#!/usr/bin/python
import wx


class Example(wx.Frame):
    def __init__(self, *args, **kw):
        super(Example, self).__init__(*args, **kw)
        self.InitUI()

    def InitUI(self):
        pnl = wx.Panel(self)
        heading = wx.StaticText(pnl, label='Body Mass Index', pos=(10, 10))
        weight = wx.StaticText(pnl, label='weight', pos=(10, 40))
        height = wx.StaticText(pnl, label='height', pos=(10, 70))
        self.weightSpin = wx.SpinCtrl(pnl, value='0', pos=(100, 40))
        self.weightSpin.SetRange(10, 500)
        self.heightSpin = wx.SpinCtrl(pnl, value='0', pos=(100, 70))
        self.heightSpin.SetRange(10, 500)

        buttonCompute = wx.Button(pnl, label="Compute", pos=(10, 120))
        buttonClose = wx.Button(pnl, label="Close", pos=(140, 120))

        buttonCompute.Bind(wx.EVT_BUTTON, self.compute)
        buttonClose.Bind(wx.EVT_BUTTON, self.close)

        self.Show(True)

    def compute(self, e):
        print(self.weightSpin.GetValue())
        print(self.heightSpin.GetValue())

    def close(self, e):
        self.Close(True)


def main():
    app = wx.App()
    Example(None)
    app.MainLoop()


if __name__ == '__main__':
    main()
