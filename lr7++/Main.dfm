object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 434
  ClientWidth = 232
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo: TMemo
    Left = 8
    Top = 8
    Width = 217
    Height = 257
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Add: TButton
    Left = 8
    Top = 298
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = AddClick
  end
  object Delete: TButton
    Left = 8
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 2
    OnClick = DeleteClick
  end
  object Search: TButton
    Left = 8
    Top = 360
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 3
    OnClick = SearchClick
  end
  object Field: TEdit
    Left = 8
    Top = 271
    Width = 89
    Height = 21
    TabOrder = 4
    TextHint = 'Field'
  end
  object Print: TButton
    Left = 8
    Top = 391
    Width = 75
    Height = 25
    Caption = 'Print'
    TabOrder = 5
    OnClick = PrintClick
  end
  object Sort: TButton
    Left = 150
    Top = 391
    Width = 75
    Height = 25
    Caption = 'Sort'
    TabOrder = 6
    OnClick = SortClick
  end
  object ListBox1: TListBox
    Left = 482
    Top = 8
    Width = 121
    Height = 257
    ItemHeight = 13
    TabOrder = 7
  end
  object FileSaveDialog1: TFileSaveDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 480
    Top = 272
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 512
    Top = 272
  end
end
