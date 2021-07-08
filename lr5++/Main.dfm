object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 403
  ClientWidth = 701
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 40
    Top = 8
    Width = 257
    Height = 201
    ItemHeight = 13
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 344
    Top = 8
    Width = 289
    Height = 201
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button1: TButton
    Left = 344
    Top = 246
    Width = 89
    Height = 25
    Caption = 'Scroll'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 40
    Top = 215
    Width = 75
    Height = 25
    Caption = 'Create queue'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 344
    Top = 215
    Width = 89
    Height = 25
    Caption = 'Print'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Pop: TButton
    Left = 344
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Pop'
    TabOrder = 5
    OnClick = PopClick
  end
  object Peek: TButton
    Left = 40
    Top = 246
    Width = 75
    Height = 25
    Caption = 'Peek'
    TabOrder = 6
    OnClick = PeekClick
  end
  object Edit1: TEdit
    Left = 344
    Top = 300
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object StaticText1: TStaticText
    Left = 344
    Top = 277
    Width = 104
    Height = 17
    Caption = 'The number of string'
    TabOrder = 8
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 656
    Top = 224
  end
end
