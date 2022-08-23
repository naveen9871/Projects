import * as React from 'react';
import {Button, View, Text, SafeAreaView} from 'react-native';

const SettingScreen = ({navigation}) => {
  return (
    <SafeAreaView style={{flex: 1}}>
      <View style={{flex: 1, padding: 16}}>
        <View
          style={{
            flex: 1,
            alignItems: 'center',
            justifyContent: 'center',
          }}>
          <Text
            style={{
              fontSize: 35,
              textAlign: 'center',
              marginBottom: 16,
            }}>
            CE0
            FORBES RANK: 1
          
            
          </Text>
          
          
          <Button
            onPress={() => navigation.navigate('ExploreScreen')}
            title="Go to COMMITTEE MEMBERS"
          />
        </View>
        <Text
          style={{
            fontSize: 18,
            textAlign: 'center',
            color: 'grey'
          }}>
          
        </Text>
        <Text
          style={{
            fontSize: 16,
            textAlign: 'center',
            color: 'grey'
          }}>
        
        </Text>
      </View>
    </SafeAreaView>
  );
};

export default SettingScreen;