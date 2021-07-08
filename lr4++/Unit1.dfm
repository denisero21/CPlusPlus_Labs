object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 370
  ClientWidth = 411
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 56
    Width = 139
    Height = 16
    Caption = 'Enter the expression:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 296
    Width = 159
    Height = 16
    Caption = 'Reverse polish notation:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 22
    Top = 113
    Width = 12
    Height = 16
    Caption = 'a:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 22
    Top = 141
    Width = 12
    Height = 16
    Caption = 'b:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 22
    Top = 169
    Width = 11
    Height = 16
    Caption = 'c:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 22
    Top = 195
    Width = 12
    Height = 16
    Caption = 'd:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 22
    Top = 221
    Width = 12
    Height = 16
    Caption = 'e:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 159
    Top = 323
    Width = 8
    Height = 13
    Caption = '='
  end
  object Label9: TLabel
    Left = 24
    Top = 22
    Width = 355
    Height = 20
    Caption = 'REVERSE POLISH NOTATION CALCULATOR'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ex_edit: TEdit
    Left = 24
    Top = 78
    Width = 129
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '(a+(b/c-d))*e'
  end
  object resex_edit: TEdit
    Left = 24
    Top = 318
    Width = 129
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object res_edit: TEdit
    Left = 173
    Top = 318
    Width = 108
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object a_edit: TEdit
    Left = 40
    Top = 108
    Width = 41
    Height = 21
    TabOrder = 3
    Text = '5,6'
  end
  object b_edit: TEdit
    Left = 40
    Top = 135
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '7,4'
  end
  object c_edit: TEdit
    Left = 40
    Top = 163
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '8,9'
  end
  object d_edit: TEdit
    Left = 40
    Top = 189
    Width = 41
    Height = 21
    TabOrder = 6
    Text = '3,1'
  end
  object e_edit: TEdit
    Left = 40
    Top = 216
    Width = 41
    Height = 21
    TabOrder = 7
    Text = '0,2'
  end
  object Button2: TButton
    Left = 24
    Top = 265
    Width = 89
    Height = 25
    Caption = 'Result'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = Button2Click
  end
end
